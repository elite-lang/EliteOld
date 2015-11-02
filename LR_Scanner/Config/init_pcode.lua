-- kind 定义
func_kind = 1
var_kind = 2
param_kind = 3
const_kind = 4

-- 下面是type定义
int_type = 1
real_type = 2
struct_type = 3
class_type = 4

-- 指令定义
LIT = 1
OPR = 2 
LOD = 3 
STO = 4 
CAL = 5 
INT = 6 
JMP = 7 
JPC = 8 
RED = 9 
WRT = 10
RET = 11
REV = 12

-- 一些杂七杂八的定义
isconstdef = false --用于const标签的属性传递
paramsum = 0
iflist = nil --这个是用于if语句的拉链
whilelist = nil
make_code( JMP, 0 ) --提前写入占位的跳转动作

function vardef( idname , data )
	if isconstdef then 
	    save_id(idname,const_kind,int_type,data)
	else
		paramsum = paramsum + 1
		save_id(idname,var_kind,int_type,paramsum)
	    if data ~= 0 then
	    	make_code(LIT,data)
	    else
	    	make_code(INT,1)
	    end
	end
end

-- id 在 运算时，首先看是否静态的
function varload( idname )
	local t = find_id(idname);
	local data = 0
    if t == nil then
        print("Error: the ID is invaild")
        exit()
    end
    print(idname, t.address);
    if t.kind == const_kind then
        make_code(LIT, t.address)
    else
    	print("LOD", t.level, t.address)
    	make_code(LOD, t.level, t.address)
    end
end

function varload_address( idname )
	local t = find_id(idname);
    if t == nil then
        print("Error: the ID is invaild")
        exit()
    end
    print(idname, t.address);
    if t.kind == var_kind then
    	print("t.level",t.level,"t.address",t.address)
        return t.level, t.address;
    end
end

function trytoCalculate( a, b, opt)
	if opt == "+" then
		make_code(OPR, 1)
	elseif opt=="-" then
		make_code(OPR, 2)
	elseif opt=="*" then
		make_code(OPR, 3)
	elseif opt=="/" then
		make_code(OPR, 4)
	end
	return nil
end

	--[[if a.data ~= nil and b.data ~= nil then
		if opt == "+" then
			return a.data + b.data
		elseif opt=="-" then
			return a.data - b.data
		elseif opt=="*" then
			return a.data * b.data
		elseif opt=="/" then
			return a.data / b.data
		end
	end 
	if a.data ~= nil then
		make_code(LIT, a.data)
	else
		print(LOD, a.level, a.address)
		make_code(LOD, a.level, a.address)
	end
	if b.data ~= nil then
		make_code(LIT, b.data)
	else
		print(LOD, b.level, b.address)
		make_code(LOD, b.level, b.address)
	end
	--]]