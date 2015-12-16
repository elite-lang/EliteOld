/* 
* @Author: sxf
* @Date:   2015-12-15 10:46:34
* @Last Modified by:   sxf
* @Last Modified time: 2015-12-16 20:38:35
*/

#include "estring.h"
extern "C" {
#include "iconv.h"
#include "charsetdetect.h"
}
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <string>
#include <fstream>
#include <streambuf>

estring::estring() {
}

estring::estring(const std::string& str) {
	*this = str;
}

estring::estring(const estring& estr) {
	*this = estr;
}

estring::estring(const char* cstr) {
	*this = cstr;
}

estring::estring(const echar_t* ecstr) {
	*this = ecstr;
}

estring::~estring() {

}

echar_t& estring::operator[] (size_t k) {
	return data.at(k);
}

const echar_t& estring::operator[] (size_t k) const {
	return data.at(k);
}

const estring& estring::operator= (const estring& estr) {
	this->data = estr.data;
}

const estring& estring::operator= (const std::string& str) {
	autoreadstr(str);
}

const estring& estring::operator= (const char* cstr) {
	autoreadstr(cstr);
}	

const estring& estring::operator= (const echar_t* ecstr) {
	this->data = ecstr;
}

bool estring::operator== (const estring& estr) {
	return this->data == estr.data;
}


void estring::autoreadfile(const std::string& path) {
	std::string str = load_full_file(path);
	readstr(str.c_str(), encodedetect(str.c_str()));
}

void estring::autoreadstr(const std::string& str) {
	readstr(str.c_str(), encodedetect(str.c_str()));
}

void estring::readfile(const std::string& path, const std::string& encode) {
	std::string str = load_full_file(path);
	readstr(str.c_str(), encode);
}

void estring::readstr (const std::string& str,  const std::string& encode) {
	readstr(str.c_str(), encode);
}

#define BUFFER_SIZE 4096

void estring::readstr (const char* data,  const std::string& encode) {
	assert (data != NULL);
	iconv_t cd = iconv_open ("UTF-16LE", encode.c_str()); // tocode, fromcode
	if ((iconv_t)-1 == cd) { 
		printf("不能从编码 %s 转换到 %s！\n", encode.c_str(), "UTF-16LE");
		return; 
	} 
	size_t in_size = strlen(data);
	size_t out_size = BUFFER_SIZE;
	size_t malloc_size = out_size;
	char* outbuf = (char*) malloc (out_size);
	char* inptr = (char*) data;
	char* outptr = outbuf;

	while(in_size != 0) {
		int nconv = iconv (cd, &inptr, &in_size, &outptr, &out_size);
		if (nconv == -1) {
			if (errno == E2BIG) {
				echar_t* buf = (echar_t*) outbuf;
				int buf_size = (BUFFER_SIZE-out_size)/2;
				for (int i = 0; i < buf_size; ++i) {
					this->data.push_back(buf[i]);
				}
				outptr = outbuf;
				out_size = BUFFER_SIZE;
			} else {
				printf ("%s\n", strerror(errno));
				free (outbuf);
				return; 
			}
		}
	}
	iconv_close (cd);
	echar_t* buf = (echar_t*) outbuf;
	int buf_size = (BUFFER_SIZE-out_size)/2;
	for (int i = 0; i < buf_size; ++i) {
		this->data.push_back(buf[i]);
	}
	free (outbuf);
}

const char* estring::c_str() {
	return (const char*)(data.data());
}

const echar_t* estring::ec_str() {
	return data.data();
}


std::string estring::to_utf8() {
	return to_str("UTF-8");
}

std::string estring::to_str(const std::string& encode) {
	iconv_t cd = iconv_open (encode.c_str(), "UTF-16LE"); // tocode, fromcode
	if ((iconv_t)-1 == cd) { 
		printf("不能从编码 %s 转换到 %s！\n", encode.c_str(), "UTF-16LE");
		return ""; 
	} 
	std::string _ToStr;
	char* data = (char*)(this->data.data());
	size_t in_size = this->data.size() * 2;
	size_t out_size = BUFFER_SIZE;
	size_t malloc_size = out_size;
	char* outbuf = (char*) malloc (out_size);
	char* inptr = data;
	char* outptr = outbuf;

	while(in_size != 0) {
		int nconv = iconv (cd, &inptr, &in_size, &outptr, &out_size);
		if (nconv == -1) {
			if (errno == E2BIG) {
				int buf_size = BUFFER_SIZE-out_size;
				for (int i = 0; i < buf_size; ++i) {
					_ToStr.push_back(outbuf[i]);
				}
				outptr = outbuf;
				out_size = BUFFER_SIZE;
			} else {
				printf ("%s\n", strerror(errno));
				free (outbuf);
				return _ToStr = ""; 
			}
		}
	}
	iconv_close (cd);
	int buf_size = BUFFER_SIZE-out_size;
	for (int i = 0; i < buf_size; ++i) {
		_ToStr.push_back(outbuf[i]);
	}
	free (outbuf);
	return _ToStr;
}


int estring::find(echar_t c) {
	int i = 0;
	for (auto p : data) {
		if (p == c) return i;
		++i; 
	}
	return -1;
}

int estring::length() {
	return data.size();
}


void estring::clear() {
	data.clear();
}

void estring::append(echar_t c) {
	data.push_back(c);
}


estring estring::substr(int begin, int end) {
	estring nestr;
	nestr.data = data.substr(begin, end);
	return nestr;
}


const char*
estring::encodedetect (const char* data) {
	assert(data != NULL);
	csd_t csd = csd_open();
    if (csd == (csd_t)-1) {
        printf("csd_open failed\n");
        return NULL;
    }

    int size = strlen(data);
    int result = csd_consider(csd, data, size);
    if (result < 0) 
        return NULL;
    return csd_close(csd);
}

std::string 
estring::load_full_file(const std::string& path) {
	std::ifstream t(path);
	std::string str;

	t.seekg(0, std::ios::end);   
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(t)),
	            std::istreambuf_iterator<char>());
	return str;
}