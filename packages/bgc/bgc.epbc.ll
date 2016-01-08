; ModuleID = 'bgc.epbc'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%"class.std::ios_base::Init" = type { i8 }
%struct._funcReg = type { i8*, void (%"class.std::shared_ptr"*, %class.CodeGenContext*, %class.Node*)* }
%"class.std::shared_ptr" = type { %"class.std::__shared_ptr" }
%"class.std::__shared_ptr" = type { %class.lvalue*, %"class.std::__shared_count" }
%class.lvalue = type { i32 (...)** }
%"class.std::__shared_count" = type { %"class.std::_Sp_counted_base"* }
%"class.std::_Sp_counted_base" = type { i32 (...)**, i32, i32 }
%class.CodeGenContext = type <{ %class.ICodeGenContext, %class.IDTable*, %class.llcg*, %class.Node*, %"class.std::map", %"class.std::stack", i8, [7 x i8] }>
%class.ICodeGenContext = type { i32 (...)** }
%class.IDTable = type opaque
%class.llcg = type { i32 (...)** }
%"class.std::map" = type { %"class.std::_Rb_tree" }
%"class.std::_Rb_tree" = type { %"struct.std::_Rb_tree<std::basic_string<char>, std::pair<const std::basic_string<char>, ICodeGenFunction *>, std::_Select1st<std::pair<const std::basic_string<char>, ICodeGenFunction *> >, std::less<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, ICodeGenFunction *> > >::_Rb_tree_impl" }
%"struct.std::_Rb_tree<std::basic_string<char>, std::pair<const std::basic_string<char>, ICodeGenFunction *>, std::_Select1st<std::pair<const std::basic_string<char>, ICodeGenFunction *> >, std::less<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, ICodeGenFunction *> > >::_Rb_tree_impl" = type { %"struct.std::less", %"struct.std::_Rb_tree_node_base", i64 }
%"struct.std::less" = type { i8 }
%"struct.std::_Rb_tree_node_base" = type { i32, %"struct.std::_Rb_tree_node_base"*, %"struct.std::_Rb_tree_node_base"*, %"struct.std::_Rb_tree_node_base"* }
%"class.std::stack" = type { %"class.std::deque" }
%"class.std::deque" = type { %"class.std::_Deque_base" }
%"class.std::_Deque_base" = type { %"struct.std::_Deque_base<std::map<std::basic_string<char>, ICodeGenFunction *, std::less<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, ICodeGenFunction *> > >, std::allocator<std::map<std::basic_string<char>, ICodeGenFunction *, std::less<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, ICodeGenFunction *> > > > >::_Deque_impl" }
%"struct.std::_Deque_base<std::map<std::basic_string<char>, ICodeGenFunction *, std::less<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, ICodeGenFunction *> > >, std::allocator<std::map<std::basic_string<char>, ICodeGenFunction *, std::less<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, ICodeGenFunction *> > > > >::_Deque_impl" = type { %"class.std::map"**, i64, %"struct.std::_Deque_iterator", %"struct.std::_Deque_iterator" }
%"struct.std::_Deque_iterator" = type { %"class.std::map"*, %"class.std::map"*, %"class.std::map"*, %"class.std::map"** }
%class.Node = type { i32 (...)**, %class.Node*, %class.Node* }
%class.TypeNode = type { %class.Node, %"class.std::basic_string", %"class.std::basic_string", i8, i8, i32 }
%"class.std::basic_string" = type { %"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Alloc_hider" }
%"struct.std::basic_string<char, std::char_traits<char>, std::allocator<char> >::_Alloc_hider" = type { i8* }
%"class.std::vector" = type { %"struct.std::_Vector_base" }
%"struct.std::_Vector_base" = type { %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl" }
%"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl" = type { %"class.std::shared_ptr"*, %"class.std::shared_ptr"*, %"class.std::shared_ptr"* }
%"class.std::allocator.3" = type { i8 }
%"class.std::allocator.6" = type { i8 }
%"class.__gnu_cxx::new_allocator.7" = type { i8 }
%"class.std::move_iterator" = type { %"class.std::shared_ptr"* }

@_ZStL8__ioinit = internal global %"class.std::ios_base::Init" zeroinitializer, align 1
@.str = private unnamed_addr constant [20 x i8] c"Bgc plugin loaded.\0A\00", align 1
@.str1 = private unnamed_addr constant [19 x i8] c"Error for context\0A\00", align 1
@_Z11macro_funcs = internal constant [2 x %struct._funcReg] [%struct._funcReg { i8* getelementptr inbounds ([8 x i8]* @.str2, i32 0, i32 0), void (%"class.std::shared_ptr"*, %class.CodeGenContext*, %class.Node*)* @_Z9new_macroP14CodeGenContextP4Node }, %struct._funcReg zeroinitializer], align 16
@.str2 = private unnamed_addr constant [8 x i8] c"new_bgc\00", align 1
@.str3 = private unnamed_addr constant [17 x i8] c"Happy New Year!\0A\00", align 1
@.str4 = private unnamed_addr constant [11 x i8] c"bgc_malloc\00", align 1
@.str5 = private unnamed_addr constant [17 x i8] c"bgc_malloc_array\00", align 1
@_ZZL18__gthread_active_pvE20__gthread_active_ptr = internal constant i8* bitcast (i32 (i32*, void (i8*)*)* @__pthread_key_create to i8*), align 8
@.str6 = private unnamed_addr constant [28 x i8] c"vector::_M_emplace_back_aux\00", align 1
@llvm.global_ctors = appending global [1 x { i32, void ()*, i8* }] [{ i32, void ()*, i8* } { i32 65535, void ()* @_GLOBAL__sub_I_main.cpp, i8* null }]

define internal void @__cxx_global_var_init() section ".text.startup" {
  call void @_ZNSt8ios_base4InitC1Ev(%"class.std::ios_base::Init"* @_ZStL8__ioinit)
  %1 = call i32 @atexit(void ()* @__dtor__ZStL8__ioinit) #2
  ret void
}

declare void @_ZNSt8ios_base4InitC1Ev(%"class.std::ios_base::Init"*) #0

; Function Attrs: nounwind
declare void @_ZNSt8ios_base4InitD1Ev(%"class.std::ios_base::Init"*) #1

define internal void @__dtor__ZStL8__ioinit() section ".text.startup" {
  call void @_ZNSt8ios_base4InitD1Ev(%"class.std::ios_base::Init"* @_ZStL8__ioinit)
  ret void
}

; Function Attrs: nounwind
declare i32 @atexit(void ()*) #2

; Function Attrs: uwtable
define void @bgc_elite_plugin_init(%class.ICodeGenContext* %context) #3 {
  %1 = alloca %class.ICodeGenContext*, align 8
  store %class.ICodeGenContext* %context, %class.ICodeGenContext** %1, align 8
  %2 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([20 x i8]* @.str, i32 0, i32 0))
  %3 = load %class.ICodeGenContext** %1, align 8
  %4 = icmp eq %class.ICodeGenContext* %3, null
  br i1 %4, label %5, label %7

; <label>:5                                       ; preds = %0
  %6 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([19 x i8]* @.str1, i32 0, i32 0))
  br label %13

; <label>:7                                       ; preds = %0
  %8 = load %class.ICodeGenContext** %1, align 8
  %9 = bitcast %class.ICodeGenContext* %8 to void (%class.ICodeGenContext*, %struct._funcReg*)***
  %10 = load void (%class.ICodeGenContext*, %struct._funcReg*)*** %9
  %11 = getelementptr inbounds void (%class.ICodeGenContext*, %struct._funcReg*)** %10, i64 7
  %12 = load void (%class.ICodeGenContext*, %struct._funcReg*)** %11
  call void %12(%class.ICodeGenContext* %8, %struct._funcReg* getelementptr inbounds ([2 x %struct._funcReg]* @_Z11macro_funcs, i32 0, i32 0))
  br label %13

; <label>:13                                      ; preds = %7, %5
  ret void
}

declare i32 @printf(i8*, ...) #0

; Function Attrs: uwtable
define internal void @_Z9new_macroP14CodeGenContextP4Node(%"class.std::shared_ptr"* noalias sret %agg.result, %class.CodeGenContext* %context, %class.Node* %node) #3 {
  %1 = alloca %class.CodeGenContext*, align 8
  %2 = alloca %class.Node*, align 8
  %tn = alloca %class.TypeNode*, align 8
  %t = alloca %"class.std::shared_ptr", align 8
  %3 = alloca i8*
  %4 = alloca i32
  %args = alloca %"class.std::vector", align 8
  %p = alloca %class.Node*, align 8
  %5 = alloca %"class.std::shared_ptr", align 8
  %6 = alloca %"class.std::shared_ptr", align 8
  %7 = alloca %"class.std::basic_string", align 8
  %8 = alloca %"class.std::allocator.3", align 1
  %9 = alloca i32
  %10 = alloca %"class.std::shared_ptr", align 8
  %11 = alloca %"class.std::basic_string", align 8
  %12 = alloca %"class.std::allocator.3", align 1
  store %class.CodeGenContext* %context, %class.CodeGenContext** %1, align 8
  store %class.Node* %node, %class.Node** %2, align 8
  %13 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([17 x i8]* @.str3, i32 0, i32 0))
  %14 = load %class.Node** %2, align 8
  %15 = bitcast %class.Node* %14 to %class.TypeNode*
  store %class.TypeNode* %15, %class.TypeNode** %tn, align 8
  %16 = load %class.CodeGenContext** %1, align 8
  %17 = bitcast %class.CodeGenContext* %16 to void (%"class.std::shared_ptr"*, %class.CodeGenContext*, %"class.std::basic_string"*)***
  %18 = load void (%"class.std::shared_ptr"*, %class.CodeGenContext*, %"class.std::basic_string"*)*** %17
  %19 = getelementptr inbounds void (%"class.std::shared_ptr"*, %class.CodeGenContext*, %"class.std::basic_string"*)** %18, i64 20
  %20 = load void (%"class.std::shared_ptr"*, %class.CodeGenContext*, %"class.std::basic_string"*)** %19
  %21 = load %class.TypeNode** %tn, align 8
  %22 = call dereferenceable(8) %"class.std::basic_string"* @_ZN8TypeNode11getTypeNameEv(%class.TypeNode* %21)
  call void %20(%"class.std::shared_ptr"* sret %t, %class.CodeGenContext* %16, %"class.std::basic_string"* dereferenceable(8) %22)
  %23 = load %class.Node** %2, align 8
  %24 = invoke %class.Node* @_ZN4Node7getNextEv(%class.Node* %23)
          to label %25 unwind label %51

; <label>:25                                      ; preds = %0
  store %class.Node* %24, %class.Node** %2, align 8
  call void @_ZNSt6vectorISt10shared_ptrI6lvalueESaIS2_EEC2Ev(%"class.std::vector"* %args) #2
  %26 = load %class.Node** %2, align 8
  %27 = invoke %class.Node* @_ZN4Node7getNextEv(%class.Node* %26)
          to label %28 unwind label %55

; <label>:28                                      ; preds = %25
  store %class.Node* %27, %class.Node** %2, align 8
  %29 = load %class.Node** %2, align 8
  %30 = icmp ne %class.Node* %29, null
  br i1 %30, label %31, label %64

; <label>:31                                      ; preds = %28
  %32 = load %class.Node** %2, align 8
  %33 = invoke %class.Node* @_ZN4Node8getChildEv(%class.Node* %32)
          to label %34 unwind label %55

; <label>:34                                      ; preds = %31
  store %class.Node* %33, %class.Node** %p, align 8
  br label %35

; <label>:35                                      ; preds = %50, %34
  %36 = load %class.Node** %p, align 8
  %37 = icmp ne %class.Node* %36, null
  br i1 %37, label %38, label %63

; <label>:38                                      ; preds = %35
  %39 = load %class.Node** %p, align 8
  %40 = bitcast %class.Node* %39 to void (%"class.std::shared_ptr"*, %class.Node*, %class.CodeGenContext*)***
  %41 = load void (%"class.std::shared_ptr"*, %class.Node*, %class.CodeGenContext*)*** %40
  %42 = getelementptr inbounds void (%"class.std::shared_ptr"*, %class.Node*, %class.CodeGenContext*)** %41, i64 3
  %43 = load void (%"class.std::shared_ptr"*, %class.Node*, %class.CodeGenContext*)** %42
  %44 = load %class.CodeGenContext** %1, align 8
  invoke void %43(%"class.std::shared_ptr"* sret %5, %class.Node* %39, %class.CodeGenContext* %44)
          to label %45 unwind label %55

; <label>:45                                      ; preds = %38
  invoke void @_ZNSt6vectorISt10shared_ptrI6lvalueESaIS2_EE9push_backEOS2_(%"class.std::vector"* %args, %"class.std::shared_ptr"* dereferenceable(16) %5)
          to label %46 unwind label %59

; <label>:46                                      ; preds = %45
  call void @_ZNSt10shared_ptrI6lvalueED2Ev(%"class.std::shared_ptr"* %5) #2
  br label %47

; <label>:47                                      ; preds = %46
  %48 = load %class.Node** %p, align 8
  %49 = invoke %class.Node* @_ZN4Node7getNextEv(%class.Node* %48)
          to label %50 unwind label %55

; <label>:50                                      ; preds = %47
  store %class.Node* %49, %class.Node** %p, align 8
  br label %35

; <label>:51                                      ; preds = %0
  %52 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %53 = extractvalue { i8*, i32 } %52, 0
  store i8* %53, i8** %3
  %54 = extractvalue { i8*, i32 } %52, 1
  store i32 %54, i32* %4
  br label %115

; <label>:55                                      ; preds = %90, %67, %47, %38, %31, %25
  %56 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %57 = extractvalue { i8*, i32 } %56, 0
  store i8* %57, i8** %3
  %58 = extractvalue { i8*, i32 } %56, 1
  store i32 %58, i32* %4
  br label %114

; <label>:59                                      ; preds = %45
  %60 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %61 = extractvalue { i8*, i32 } %60, 0
  store i8* %61, i8** %3
  %62 = extractvalue { i8*, i32 } %60, 1
  store i32 %62, i32* %4
  call void @_ZNSt10shared_ptrI6lvalueED2Ev(%"class.std::shared_ptr"* %5) #2
  br label %114

; <label>:63                                      ; preds = %35
  br label %64

; <label>:64                                      ; preds = %63, %28
  %65 = call i64 @_ZNKSt6vectorISt10shared_ptrI6lvalueESaIS2_EE4sizeEv(%"class.std::vector"* %args) #2
  %66 = icmp eq i64 %65, 0
  br i1 %66, label %67, label %90

; <label>:67                                      ; preds = %64
  %68 = load %class.CodeGenContext** %1, align 8
  %69 = bitcast %class.CodeGenContext* %68 to %class.llcg* (%class.CodeGenContext*)***
  %70 = load %class.llcg* (%class.CodeGenContext*)*** %69
  %71 = getelementptr inbounds %class.llcg* (%class.CodeGenContext*)** %70, i64 30
  %72 = load %class.llcg* (%class.CodeGenContext*)** %71
  %73 = invoke %class.llcg* %72(%class.CodeGenContext* %68)
          to label %74 unwind label %55

; <label>:74                                      ; preds = %67
  %75 = bitcast %class.llcg* %73 to void (%"class.std::shared_ptr"*, %class.llcg*, %"class.std::shared_ptr"*, %"class.std::vector"*, %"class.std::basic_string"*)***
  %76 = load void (%"class.std::shared_ptr"*, %class.llcg*, %"class.std::shared_ptr"*, %"class.std::vector"*, %"class.std::basic_string"*)*** %75
  %77 = getelementptr inbounds void (%"class.std::shared_ptr"*, %class.llcg*, %"class.std::shared_ptr"*, %"class.std::vector"*, %"class.std::basic_string"*)** %76, i64 30
  %78 = load void (%"class.std::shared_ptr"*, %class.llcg*, %"class.std::shared_ptr"*, %"class.std::vector"*, %"class.std::basic_string"*)** %77
  call void @_ZNSt10shared_ptrI6lvalueEC2ERKS1_(%"class.std::shared_ptr"* %6, %"class.std::shared_ptr"* dereferenceable(16) %t) #2
  call void @_ZNSaIcEC1Ev(%"class.std::allocator.3"* %8) #2
  invoke void @_ZNSsC1EPKcRKSaIcE(%"class.std::basic_string"* %7, i8* getelementptr inbounds ([11 x i8]* @.str4, i32 0, i32 0), %"class.std::allocator.3"* dereferenceable(1) %8)
          to label %79 unwind label %81

; <label>:79                                      ; preds = %74
  invoke void %78(%"class.std::shared_ptr"* sret %agg.result, %class.llcg* %73, %"class.std::shared_ptr"* %6, %"class.std::vector"* dereferenceable(24) %args, %"class.std::basic_string"* dereferenceable(8) %7)
          to label %80 unwind label %85

; <label>:80                                      ; preds = %79
  call void @_ZNSsD1Ev(%"class.std::basic_string"* %7) #2
  call void @_ZNSaIcED1Ev(%"class.std::allocator.3"* %8) #2
  call void @_ZNSt10shared_ptrI6lvalueED2Ev(%"class.std::shared_ptr"* %6) #2
  store i32 1, i32* %9
  br label %113

; <label>:81                                      ; preds = %74
  %82 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %83 = extractvalue { i8*, i32 } %82, 0
  store i8* %83, i8** %3
  %84 = extractvalue { i8*, i32 } %82, 1
  store i32 %84, i32* %4
  br label %89

; <label>:85                                      ; preds = %79
  %86 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %87 = extractvalue { i8*, i32 } %86, 0
  store i8* %87, i8** %3
  %88 = extractvalue { i8*, i32 } %86, 1
  store i32 %88, i32* %4
  call void @_ZNSsD1Ev(%"class.std::basic_string"* %7) #2
  br label %89

; <label>:89                                      ; preds = %85, %81
  call void @_ZNSaIcED1Ev(%"class.std::allocator.3"* %8) #2
  call void @_ZNSt10shared_ptrI6lvalueED2Ev(%"class.std::shared_ptr"* %6) #2
  br label %114

; <label>:90                                      ; preds = %64
  %91 = load %class.CodeGenContext** %1, align 8
  %92 = bitcast %class.CodeGenContext* %91 to %class.llcg* (%class.CodeGenContext*)***
  %93 = load %class.llcg* (%class.CodeGenContext*)*** %92
  %94 = getelementptr inbounds %class.llcg* (%class.CodeGenContext*)** %93, i64 30
  %95 = load %class.llcg* (%class.CodeGenContext*)** %94
  %96 = invoke %class.llcg* %95(%class.CodeGenContext* %91)
          to label %97 unwind label %55

; <label>:97                                      ; preds = %90
  %98 = bitcast %class.llcg* %96 to void (%"class.std::shared_ptr"*, %class.llcg*, %"class.std::shared_ptr"*, %"class.std::vector"*, %"class.std::basic_string"*)***
  %99 = load void (%"class.std::shared_ptr"*, %class.llcg*, %"class.std::shared_ptr"*, %"class.std::vector"*, %"class.std::basic_string"*)*** %98
  %100 = getelementptr inbounds void (%"class.std::shared_ptr"*, %class.llcg*, %"class.std::shared_ptr"*, %"class.std::vector"*, %"class.std::basic_string"*)** %99, i64 31
  %101 = load void (%"class.std::shared_ptr"*, %class.llcg*, %"class.std::shared_ptr"*, %"class.std::vector"*, %"class.std::basic_string"*)** %100
  call void @_ZNSt10shared_ptrI6lvalueEC2ERKS1_(%"class.std::shared_ptr"* %10, %"class.std::shared_ptr"* dereferenceable(16) %t) #2
  call void @_ZNSaIcEC1Ev(%"class.std::allocator.3"* %12) #2
  invoke void @_ZNSsC1EPKcRKSaIcE(%"class.std::basic_string"* %11, i8* getelementptr inbounds ([17 x i8]* @.str5, i32 0, i32 0), %"class.std::allocator.3"* dereferenceable(1) %12)
          to label %102 unwind label %104

; <label>:102                                     ; preds = %97
  invoke void %101(%"class.std::shared_ptr"* sret %agg.result, %class.llcg* %96, %"class.std::shared_ptr"* %10, %"class.std::vector"* dereferenceable(24) %args, %"class.std::basic_string"* dereferenceable(8) %11)
          to label %103 unwind label %108

; <label>:103                                     ; preds = %102
  call void @_ZNSsD1Ev(%"class.std::basic_string"* %11) #2
  call void @_ZNSaIcED1Ev(%"class.std::allocator.3"* %12) #2
  call void @_ZNSt10shared_ptrI6lvalueED2Ev(%"class.std::shared_ptr"* %10) #2
  store i32 1, i32* %9
  br label %113

; <label>:104                                     ; preds = %97
  %105 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %106 = extractvalue { i8*, i32 } %105, 0
  store i8* %106, i8** %3
  %107 = extractvalue { i8*, i32 } %105, 1
  store i32 %107, i32* %4
  br label %112

; <label>:108                                     ; preds = %102
  %109 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %110 = extractvalue { i8*, i32 } %109, 0
  store i8* %110, i8** %3
  %111 = extractvalue { i8*, i32 } %109, 1
  store i32 %111, i32* %4
  call void @_ZNSsD1Ev(%"class.std::basic_string"* %11) #2
  br label %112

; <label>:112                                     ; preds = %108, %104
  call void @_ZNSaIcED1Ev(%"class.std::allocator.3"* %12) #2
  call void @_ZNSt10shared_ptrI6lvalueED2Ev(%"class.std::shared_ptr"* %10) #2
  br label %114

; <label>:113                                     ; preds = %103, %80
  call void @_ZNSt6vectorISt10shared_ptrI6lvalueESaIS2_EED2Ev(%"class.std::vector"* %args) #2
  call void @_ZNSt10shared_ptrI6lvalueED2Ev(%"class.std::shared_ptr"* %t) #2
  ret void

; <label>:114                                     ; preds = %112, %89, %59, %55
  call void @_ZNSt6vectorISt10shared_ptrI6lvalueESaIS2_EED2Ev(%"class.std::vector"* %args) #2
  br label %115

; <label>:115                                     ; preds = %114, %51
  call void @_ZNSt10shared_ptrI6lvalueED2Ev(%"class.std::shared_ptr"* %t) #2
  br label %116

; <label>:116                                     ; preds = %115
  %117 = load i8** %3
  %118 = load i32* %4
  %119 = insertvalue { i8*, i32 } undef, i8* %117, 0
  %120 = insertvalue { i8*, i32 } %119, i32 %118, 1
  resume { i8*, i32 } %120
}

declare dereferenceable(8) %"class.std::basic_string"* @_ZN8TypeNode11getTypeNameEv(%class.TypeNode*) #0

; Function Attrs: nounwind uwtable
define linkonce_odr %class.Node* @_ZN4Node7getNextEv(%class.Node* %this) #4 align 2 {
  %1 = alloca %class.Node*, align 8
  store %class.Node* %this, %class.Node** %1, align 8
  %2 = load %class.Node** %1
  %3 = getelementptr inbounds %class.Node* %2, i32 0, i32 1
  %4 = load %class.Node** %3, align 8
  ret %class.Node* %4
}

declare i32 @__gxx_personality_v0(...)

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt6vectorISt10shared_ptrI6lvalueESaIS2_EEC2Ev(%"class.std::vector"* %this) unnamed_addr #4 align 2 {
  %1 = alloca %"class.std::vector"*, align 8
  store %"class.std::vector"* %this, %"class.std::vector"** %1, align 8
  %2 = load %"class.std::vector"** %1
  %3 = bitcast %"class.std::vector"* %2 to %"struct.std::_Vector_base"*
  invoke void @_ZNSt12_Vector_baseISt10shared_ptrI6lvalueESaIS2_EEC2Ev(%"struct.std::_Vector_base"* %3)
          to label %4 unwind label %5

; <label>:4                                       ; preds = %0
  ret void

; <label>:5                                       ; preds = %0
  %6 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %7 = extractvalue { i8*, i32 } %6, 0
  call void @__clang_call_terminate(i8* %7) #9
  unreachable
}

; Function Attrs: nounwind uwtable
define linkonce_odr %class.Node* @_ZN4Node8getChildEv(%class.Node* %this) #4 align 2 {
  %1 = alloca %class.Node*, align 8
  store %class.Node* %this, %class.Node** %1, align 8
  %2 = load %class.Node** %1
  %3 = getelementptr inbounds %class.Node* %2, i32 0, i32 2
  %4 = load %class.Node** %3, align 8
  ret %class.Node* %4
}

; Function Attrs: uwtable
define linkonce_odr void @_ZNSt6vectorISt10shared_ptrI6lvalueESaIS2_EE9push_backEOS2_(%"class.std::vector"* %this, %"class.std::shared_ptr"* dereferenceable(16) %__x) #3 align 2 {
  %1 = alloca %"class.std::vector"*, align 8
  %2 = alloca %"class.std::shared_ptr"*, align 8
  store %"class.std::vector"* %this, %"class.std::vector"** %1, align 8
  store %"class.std::shared_ptr"* %__x, %"class.std::shared_ptr"** %2, align 8
  %3 = load %"class.std::vector"** %1
  %4 = load %"class.std::shared_ptr"** %2, align 8
  %5 = call dereferenceable(16) %"class.std::shared_ptr"* @_ZSt4moveIRSt10shared_ptrI6lvalueEEONSt16remove_referenceIT_E4typeEOS5_(%"class.std::shared_ptr"* dereferenceable(16) %4) #2
  call void @_ZNSt6vectorISt10shared_ptrI6lvalueESaIS2_EE12emplace_backIJS2_EEEvDpOT_(%"class.std::vector"* %3, %"class.std::shared_ptr"* dereferenceable(16) %5)
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZNSt10shared_ptrI6lvalueED2Ev(%"class.std::shared_ptr"* %this) unnamed_addr #5 align 2 {
  %1 = alloca %"class.std::shared_ptr"*, align 8
  store %"class.std::shared_ptr"* %this, %"class.std::shared_ptr"** %1, align 8
  %2 = load %"class.std::shared_ptr"** %1
  %3 = bitcast %"class.std::shared_ptr"* %2 to %"class.std::__shared_ptr"*
  call void @_ZNSt12__shared_ptrI6lvalueLN9__gnu_cxx12_Lock_policyE2EED2Ev(%"class.std::__shared_ptr"* %3) #2
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt6vectorISt10shared_ptrI6lvalueESaIS2_EE4sizeEv(%"class.std::vector"* %this) #4 align 2 {
  %1 = alloca %"class.std::vector"*, align 8
  store %"class.std::vector"* %this, %"class.std::vector"** %1, align 8
  %2 = load %"class.std::vector"** %1
  %3 = bitcast %"class.std::vector"* %2 to %"struct.std::_Vector_base"*
  %4 = getelementptr inbounds %"struct.std::_Vector_base"* %3, i32 0, i32 0
  %5 = getelementptr inbounds %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %4, i32 0, i32 1
  %6 = load %"class.std::shared_ptr"** %5, align 8
  %7 = bitcast %"class.std::vector"* %2 to %"struct.std::_Vector_base"*
  %8 = getelementptr inbounds %"struct.std::_Vector_base"* %7, i32 0, i32 0
  %9 = getelementptr inbounds %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %8, i32 0, i32 0
  %10 = load %"class.std::shared_ptr"** %9, align 8
  %11 = ptrtoint %"class.std::shared_ptr"* %6 to i64
  %12 = ptrtoint %"class.std::shared_ptr"* %10 to i64
  %13 = sub i64 %11, %12
  %14 = sdiv exact i64 %13, 16
  ret i64 %14
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt10shared_ptrI6lvalueEC2ERKS1_(%"class.std::shared_ptr"* %this, %"class.std::shared_ptr"* dereferenceable(16)) unnamed_addr #4 align 2 {
  %2 = alloca %"class.std::shared_ptr"*, align 8
  %3 = alloca %"class.std::shared_ptr"*, align 8
  store %"class.std::shared_ptr"* %this, %"class.std::shared_ptr"** %2, align 8
  store %"class.std::shared_ptr"* %0, %"class.std::shared_ptr"** %3, align 8
  %4 = load %"class.std::shared_ptr"** %2
  %5 = bitcast %"class.std::shared_ptr"* %4 to %"class.std::__shared_ptr"*
  %6 = load %"class.std::shared_ptr"** %3, align 8
  %7 = bitcast %"class.std::shared_ptr"* %6 to %"class.std::__shared_ptr"*
  call void @_ZNSt12__shared_ptrI6lvalueLN9__gnu_cxx12_Lock_policyE2EEC2ERKS3_(%"class.std::__shared_ptr"* %5, %"class.std::__shared_ptr"* dereferenceable(16) %7) #2
  ret void
}

; Function Attrs: nounwind
declare void @_ZNSaIcEC1Ev(%"class.std::allocator.3"*) #1

declare void @_ZNSsC1EPKcRKSaIcE(%"class.std::basic_string"*, i8*, %"class.std::allocator.3"* dereferenceable(1)) #0

; Function Attrs: nounwind
declare void @_ZNSsD1Ev(%"class.std::basic_string"*) #1

; Function Attrs: nounwind
declare void @_ZNSaIcED1Ev(%"class.std::allocator.3"*) #1

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt6vectorISt10shared_ptrI6lvalueESaIS2_EED2Ev(%"class.std::vector"* %this) unnamed_addr #4 align 2 {
  %1 = alloca %"class.std::vector"*, align 8
  %2 = alloca i8*
  %3 = alloca i32
  store %"class.std::vector"* %this, %"class.std::vector"** %1, align 8
  %4 = load %"class.std::vector"** %1
  %5 = bitcast %"class.std::vector"* %4 to %"struct.std::_Vector_base"*
  %6 = getelementptr inbounds %"struct.std::_Vector_base"* %5, i32 0, i32 0
  %7 = getelementptr inbounds %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %6, i32 0, i32 0
  %8 = load %"class.std::shared_ptr"** %7, align 8
  %9 = bitcast %"class.std::vector"* %4 to %"struct.std::_Vector_base"*
  %10 = getelementptr inbounds %"struct.std::_Vector_base"* %9, i32 0, i32 0
  %11 = getelementptr inbounds %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %10, i32 0, i32 1
  %12 = load %"class.std::shared_ptr"** %11, align 8
  %13 = bitcast %"class.std::vector"* %4 to %"struct.std::_Vector_base"*
  %14 = call dereferenceable(1) %"class.std::allocator.6"* @_ZNSt12_Vector_baseISt10shared_ptrI6lvalueESaIS2_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base"* %13) #2
  invoke void @_ZSt8_DestroyIPSt10shared_ptrI6lvalueES2_EvT_S4_RSaIT0_E(%"class.std::shared_ptr"* %8, %"class.std::shared_ptr"* %12, %"class.std::allocator.6"* dereferenceable(1) %14)
          to label %15 unwind label %17

; <label>:15                                      ; preds = %0
  %16 = bitcast %"class.std::vector"* %4 to %"struct.std::_Vector_base"*
  call void @_ZNSt12_Vector_baseISt10shared_ptrI6lvalueESaIS2_EED2Ev(%"struct.std::_Vector_base"* %16) #2
  ret void

; <label>:17                                      ; preds = %0
  %18 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %19 = extractvalue { i8*, i32 } %18, 0
  store i8* %19, i8** %2
  %20 = extractvalue { i8*, i32 } %18, 1
  store i32 %20, i32* %3
  %21 = bitcast %"class.std::vector"* %4 to %"struct.std::_Vector_base"*
  call void @_ZNSt12_Vector_baseISt10shared_ptrI6lvalueESaIS2_EED2Ev(%"struct.std::_Vector_base"* %21) #2
  br label %22

; <label>:22                                      ; preds = %17
  %23 = load i8** %2
  call void @__clang_call_terminate(i8* %23) #9
  unreachable
}

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZSt8_DestroyIPSt10shared_ptrI6lvalueES2_EvT_S4_RSaIT0_E(%"class.std::shared_ptr"* %__first, %"class.std::shared_ptr"* %__last, %"class.std::allocator.6"* dereferenceable(1)) #6 {
  %2 = alloca %"class.std::shared_ptr"*, align 8
  %3 = alloca %"class.std::shared_ptr"*, align 8
  %4 = alloca %"class.std::allocator.6"*, align 8
  store %"class.std::shared_ptr"* %__first, %"class.std::shared_ptr"** %2, align 8
  store %"class.std::shared_ptr"* %__last, %"class.std::shared_ptr"** %3, align 8
  store %"class.std::allocator.6"* %0, %"class.std::allocator.6"** %4, align 8
  %5 = load %"class.std::shared_ptr"** %2, align 8
  %6 = load %"class.std::shared_ptr"** %3, align 8
  call void @_ZSt8_DestroyIPSt10shared_ptrI6lvalueEEvT_S4_(%"class.std::shared_ptr"* %5, %"class.std::shared_ptr"* %6)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(1) %"class.std::allocator.6"* @_ZNSt12_Vector_baseISt10shared_ptrI6lvalueESaIS2_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base"* %this) #4 align 2 {
  %1 = alloca %"struct.std::_Vector_base"*, align 8
  store %"struct.std::_Vector_base"* %this, %"struct.std::_Vector_base"** %1, align 8
  %2 = load %"struct.std::_Vector_base"** %1
  %3 = getelementptr inbounds %"struct.std::_Vector_base"* %2, i32 0, i32 0
  %4 = bitcast %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %3 to %"class.std::allocator.6"*
  ret %"class.std::allocator.6"* %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt12_Vector_baseISt10shared_ptrI6lvalueESaIS2_EED2Ev(%"struct.std::_Vector_base"* %this) unnamed_addr #4 align 2 {
  %1 = alloca %"struct.std::_Vector_base"*, align 8
  %2 = alloca i8*
  %3 = alloca i32
  store %"struct.std::_Vector_base"* %this, %"struct.std::_Vector_base"** %1, align 8
  %4 = load %"struct.std::_Vector_base"** %1
  %5 = getelementptr inbounds %"struct.std::_Vector_base"* %4, i32 0, i32 0
  %6 = getelementptr inbounds %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %5, i32 0, i32 0
  %7 = load %"class.std::shared_ptr"** %6, align 8
  %8 = getelementptr inbounds %"struct.std::_Vector_base"* %4, i32 0, i32 0
  %9 = getelementptr inbounds %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %8, i32 0, i32 2
  %10 = load %"class.std::shared_ptr"** %9, align 8
  %11 = getelementptr inbounds %"struct.std::_Vector_base"* %4, i32 0, i32 0
  %12 = getelementptr inbounds %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %11, i32 0, i32 0
  %13 = load %"class.std::shared_ptr"** %12, align 8
  %14 = ptrtoint %"class.std::shared_ptr"* %10 to i64
  %15 = ptrtoint %"class.std::shared_ptr"* %13 to i64
  %16 = sub i64 %14, %15
  %17 = sdiv exact i64 %16, 16
  invoke void @_ZNSt12_Vector_baseISt10shared_ptrI6lvalueESaIS2_EE13_M_deallocateEPS2_m(%"struct.std::_Vector_base"* %4, %"class.std::shared_ptr"* %7, i64 %17)
          to label %18 unwind label %20

; <label>:18                                      ; preds = %0
  %19 = getelementptr inbounds %"struct.std::_Vector_base"* %4, i32 0, i32 0
  call void @_ZNSt12_Vector_baseISt10shared_ptrI6lvalueESaIS2_EE12_Vector_implD2Ev(%"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %19) #2
  ret void

; <label>:20                                      ; preds = %0
  %21 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %22 = extractvalue { i8*, i32 } %21, 0
  store i8* %22, i8** %2
  %23 = extractvalue { i8*, i32 } %21, 1
  store i32 %23, i32* %3
  %24 = getelementptr inbounds %"struct.std::_Vector_base"* %4, i32 0, i32 0
  call void @_ZNSt12_Vector_baseISt10shared_ptrI6lvalueESaIS2_EE12_Vector_implD2Ev(%"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %24) #2
  br label %25

; <label>:25                                      ; preds = %20
  %26 = load i8** %2
  call void @__clang_call_terminate(i8* %26) #9
  unreachable
}

; Function Attrs: noinline noreturn nounwind
define linkonce_odr hidden void @__clang_call_terminate(i8*) #7 {
  %2 = call i8* @__cxa_begin_catch(i8* %0) #2
  call void @_ZSt9terminatev() #9
  unreachable
}

declare i8* @__cxa_begin_catch(i8*)

declare void @_ZSt9terminatev()

; Function Attrs: uwtable
define linkonce_odr void @_ZNSt12_Vector_baseISt10shared_ptrI6lvalueESaIS2_EE13_M_deallocateEPS2_m(%"struct.std::_Vector_base"* %this, %"class.std::shared_ptr"* %__p, i64 %__n) #3 align 2 {
  %1 = alloca %"struct.std::_Vector_base"*, align 8
  %2 = alloca %"class.std::shared_ptr"*, align 8
  %3 = alloca i64, align 8
  store %"struct.std::_Vector_base"* %this, %"struct.std::_Vector_base"** %1, align 8
  store %"class.std::shared_ptr"* %__p, %"class.std::shared_ptr"** %2, align 8
  store i64 %__n, i64* %3, align 8
  %4 = load %"struct.std::_Vector_base"** %1
  %5 = load %"class.std::shared_ptr"** %2, align 8
  %6 = icmp ne %"class.std::shared_ptr"* %5, null
  br i1 %6, label %7, label %12

; <label>:7                                       ; preds = %0
  %8 = getelementptr inbounds %"struct.std::_Vector_base"* %4, i32 0, i32 0
  %9 = bitcast %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %8 to %"class.std::allocator.6"*
  %10 = load %"class.std::shared_ptr"** %2, align 8
  %11 = load i64* %3, align 8
  call void @_ZNSt16allocator_traitsISaISt10shared_ptrI6lvalueEEE10deallocateERS3_PS2_m(%"class.std::allocator.6"* dereferenceable(1) %9, %"class.std::shared_ptr"* %10, i64 %11)
  br label %12

; <label>:12                                      ; preds = %7, %0
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZNSt12_Vector_baseISt10shared_ptrI6lvalueESaIS2_EE12_Vector_implD2Ev(%"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %this) unnamed_addr #5 align 2 {
  %1 = alloca %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"*, align 8
  store %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %this, %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"** %1, align 8
  %2 = load %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"** %1
  %3 = bitcast %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %2 to %"class.std::allocator.6"*
  call void @_ZNSaISt10shared_ptrI6lvalueEED2Ev(%"class.std::allocator.6"* %3) #2
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSaISt10shared_ptrI6lvalueEED2Ev(%"class.std::allocator.6"* %this) unnamed_addr #4 align 2 {
  %1 = alloca %"class.std::allocator.6"*, align 8
  store %"class.std::allocator.6"* %this, %"class.std::allocator.6"** %1, align 8
  %2 = load %"class.std::allocator.6"** %1
  %3 = bitcast %"class.std::allocator.6"* %2 to %"class.__gnu_cxx::new_allocator.7"*
  call void @_ZN9__gnu_cxx13new_allocatorISt10shared_ptrI6lvalueEED2Ev(%"class.__gnu_cxx::new_allocator.7"* %3) #2
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx13new_allocatorISt10shared_ptrI6lvalueEED2Ev(%"class.__gnu_cxx::new_allocator.7"* %this) unnamed_addr #4 align 2 {
  %1 = alloca %"class.__gnu_cxx::new_allocator.7"*, align 8
  store %"class.__gnu_cxx::new_allocator.7"* %this, %"class.__gnu_cxx::new_allocator.7"** %1, align 8
  %2 = load %"class.__gnu_cxx::new_allocator.7"** %1
  ret void
}

; Function Attrs: uwtable
define linkonce_odr void @_ZNSt16allocator_traitsISaISt10shared_ptrI6lvalueEEE10deallocateERS3_PS2_m(%"class.std::allocator.6"* dereferenceable(1) %__a, %"class.std::shared_ptr"* %__p, i64 %__n) #3 align 2 {
  %1 = alloca %"class.std::allocator.6"*, align 8
  %2 = alloca %"class.std::shared_ptr"*, align 8
  %3 = alloca i64, align 8
  store %"class.std::allocator.6"* %__a, %"class.std::allocator.6"** %1, align 8
  store %"class.std::shared_ptr"* %__p, %"class.std::shared_ptr"** %2, align 8
  store i64 %__n, i64* %3, align 8
  %4 = load %"class.std::allocator.6"** %1, align 8
  %5 = bitcast %"class.std::allocator.6"* %4 to %"class.__gnu_cxx::new_allocator.7"*
  %6 = load %"class.std::shared_ptr"** %2, align 8
  %7 = load i64* %3, align 8
  call void @_ZN9__gnu_cxx13new_allocatorISt10shared_ptrI6lvalueEE10deallocateEPS3_m(%"class.__gnu_cxx::new_allocator.7"* %5, %"class.std::shared_ptr"* %6, i64 %7)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx13new_allocatorISt10shared_ptrI6lvalueEE10deallocateEPS3_m(%"class.__gnu_cxx::new_allocator.7"* %this, %"class.std::shared_ptr"* %__p, i64) #4 align 2 {
  %2 = alloca %"class.__gnu_cxx::new_allocator.7"*, align 8
  %3 = alloca %"class.std::shared_ptr"*, align 8
  %4 = alloca i64, align 8
  store %"class.__gnu_cxx::new_allocator.7"* %this, %"class.__gnu_cxx::new_allocator.7"** %2, align 8
  store %"class.std::shared_ptr"* %__p, %"class.std::shared_ptr"** %3, align 8
  store i64 %0, i64* %4, align 8
  %5 = load %"class.__gnu_cxx::new_allocator.7"** %2
  %6 = load %"class.std::shared_ptr"** %3, align 8
  %7 = bitcast %"class.std::shared_ptr"* %6 to i8*
  call void @_ZdlPv(i8* %7) #2
  ret void
}

; Function Attrs: nobuiltin nounwind
declare void @_ZdlPv(i8*) #8

; Function Attrs: inlinehint uwtable
define linkonce_odr void @_ZSt8_DestroyIPSt10shared_ptrI6lvalueEEvT_S4_(%"class.std::shared_ptr"* %__first, %"class.std::shared_ptr"* %__last) #6 {
  %1 = alloca %"class.std::shared_ptr"*, align 8
  %2 = alloca %"class.std::shared_ptr"*, align 8
  store %"class.std::shared_ptr"* %__first, %"class.std::shared_ptr"** %1, align 8
  store %"class.std::shared_ptr"* %__last, %"class.std::shared_ptr"** %2, align 8
  %3 = load %"class.std::shared_ptr"** %1, align 8
  %4 = load %"class.std::shared_ptr"** %2, align 8
  call void @_ZNSt12_Destroy_auxILb0EE9__destroyIPSt10shared_ptrI6lvalueEEEvT_S6_(%"class.std::shared_ptr"* %3, %"class.std::shared_ptr"* %4)
  ret void
}

; Function Attrs: uwtable
define linkonce_odr void @_ZNSt12_Destroy_auxILb0EE9__destroyIPSt10shared_ptrI6lvalueEEEvT_S6_(%"class.std::shared_ptr"* %__first, %"class.std::shared_ptr"* %__last) #3 align 2 {
  %1 = alloca %"class.std::shared_ptr"*, align 8
  %2 = alloca %"class.std::shared_ptr"*, align 8
  store %"class.std::shared_ptr"* %__first, %"class.std::shared_ptr"** %1, align 8
  store %"class.std::shared_ptr"* %__last, %"class.std::shared_ptr"** %2, align 8
  br label %3

; <label>:3                                       ; preds = %10, %0
  %4 = load %"class.std::shared_ptr"** %1, align 8
  %5 = load %"class.std::shared_ptr"** %2, align 8
  %6 = icmp ne %"class.std::shared_ptr"* %4, %5
  br i1 %6, label %7, label %13

; <label>:7                                       ; preds = %3
  %8 = load %"class.std::shared_ptr"** %1, align 8
  %9 = call %"class.std::shared_ptr"* @_ZSt11__addressofISt10shared_ptrI6lvalueEEPT_RS3_(%"class.std::shared_ptr"* dereferenceable(16) %8) #2
  call void @_ZSt8_DestroyISt10shared_ptrI6lvalueEEvPT_(%"class.std::shared_ptr"* %9)
  br label %10

; <label>:10                                      ; preds = %7
  %11 = load %"class.std::shared_ptr"** %1, align 8
  %12 = getelementptr inbounds %"class.std::shared_ptr"* %11, i32 1
  store %"class.std::shared_ptr"* %12, %"class.std::shared_ptr"** %1, align 8
  br label %3

; <label>:13                                      ; preds = %3
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZSt8_DestroyISt10shared_ptrI6lvalueEEvPT_(%"class.std::shared_ptr"* %__pointer) #5 {
  %1 = alloca %"class.std::shared_ptr"*, align 8
  store %"class.std::shared_ptr"* %__pointer, %"class.std::shared_ptr"** %1, align 8
  %2 = load %"class.std::shared_ptr"** %1, align 8
  call void @_ZNSt10shared_ptrI6lvalueED2Ev(%"class.std::shared_ptr"* %2) #2
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr %"class.std::shared_ptr"* @_ZSt11__addressofISt10shared_ptrI6lvalueEEPT_RS3_(%"class.std::shared_ptr"* dereferenceable(16) %__r) #5 {
  %1 = alloca %"class.std::shared_ptr"*, align 8
  store %"class.std::shared_ptr"* %__r, %"class.std::shared_ptr"** %1, align 8
  %2 = load %"class.std::shared_ptr"** %1, align 8
  %3 = bitcast %"class.std::shared_ptr"* %2 to i8*
  %4 = bitcast i8* %3 to %"class.std::shared_ptr"*
  ret %"class.std::shared_ptr"* %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt12__shared_ptrI6lvalueLN9__gnu_cxx12_Lock_policyE2EEC2ERKS3_(%"class.std::__shared_ptr"* %this, %"class.std::__shared_ptr"* dereferenceable(16)) unnamed_addr #4 align 2 {
  %2 = alloca %"class.std::__shared_ptr"*, align 8
  %3 = alloca %"class.std::__shared_ptr"*, align 8
  store %"class.std::__shared_ptr"* %this, %"class.std::__shared_ptr"** %2, align 8
  store %"class.std::__shared_ptr"* %0, %"class.std::__shared_ptr"** %3, align 8
  %4 = load %"class.std::__shared_ptr"** %2
  %5 = getelementptr inbounds %"class.std::__shared_ptr"* %4, i32 0, i32 0
  %6 = load %"class.std::__shared_ptr"** %3, align 8
  %7 = getelementptr inbounds %"class.std::__shared_ptr"* %6, i32 0, i32 0
  %8 = load %class.lvalue** %7, align 8
  store %class.lvalue* %8, %class.lvalue** %5, align 8
  %9 = getelementptr inbounds %"class.std::__shared_ptr"* %4, i32 0, i32 1
  %10 = load %"class.std::__shared_ptr"** %3, align 8
  %11 = getelementptr inbounds %"class.std::__shared_ptr"* %10, i32 0, i32 1
  call void @_ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EEC2ERKS2_(%"class.std::__shared_count"* %9, %"class.std::__shared_count"* dereferenceable(8) %11) #2
  %12 = getelementptr inbounds %"class.std::__shared_ptr"* %4, i32 0, i32 0
  %13 = load %"class.std::__shared_ptr"** %3, align 8
  %14 = getelementptr inbounds %"class.std::__shared_ptr"* %13, i32 0, i32 0
  %15 = load %class.lvalue** %14, align 8
  store %class.lvalue* %15, %class.lvalue** %12, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EEC2ERKS2_(%"class.std::__shared_count"* %this, %"class.std::__shared_count"* dereferenceable(8) %__r) unnamed_addr #4 align 2 {
  %1 = alloca %"class.std::__shared_count"*, align 8
  %2 = alloca %"class.std::__shared_count"*, align 8
  store %"class.std::__shared_count"* %this, %"class.std::__shared_count"** %1, align 8
  store %"class.std::__shared_count"* %__r, %"class.std::__shared_count"** %2, align 8
  %3 = load %"class.std::__shared_count"** %1
  %4 = getelementptr inbounds %"class.std::__shared_count"* %3, i32 0, i32 0
  %5 = load %"class.std::__shared_count"** %2, align 8
  %6 = getelementptr inbounds %"class.std::__shared_count"* %5, i32 0, i32 0
  %7 = load %"class.std::_Sp_counted_base"** %6, align 8
  store %"class.std::_Sp_counted_base"* %7, %"class.std::_Sp_counted_base"** %4, align 8
  %8 = getelementptr inbounds %"class.std::__shared_count"* %3, i32 0, i32 0
  %9 = load %"class.std::_Sp_counted_base"** %8, align 8
  %10 = icmp ne %"class.std::_Sp_counted_base"* %9, null
  br i1 %10, label %11, label %15

; <label>:11                                      ; preds = %0
  %12 = getelementptr inbounds %"class.std::__shared_count"* %3, i32 0, i32 0
  %13 = load %"class.std::_Sp_counted_base"** %12, align 8
  invoke void @_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE15_M_add_ref_copyEv(%"class.std::_Sp_counted_base"* %13)
          to label %14 unwind label %16

; <label>:14                                      ; preds = %11
  br label %15

; <label>:15                                      ; preds = %14, %0
  ret void

; <label>:16                                      ; preds = %11
  %17 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %18 = extractvalue { i8*, i32 } %17, 0
  call void @__clang_call_terminate(i8* %18) #9
  unreachable
}

; Function Attrs: uwtable
define linkonce_odr void @_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE15_M_add_ref_copyEv(%"class.std::_Sp_counted_base"* %this) #3 align 2 {
  %1 = alloca %"class.std::_Sp_counted_base"*, align 8
  store %"class.std::_Sp_counted_base"* %this, %"class.std::_Sp_counted_base"** %1, align 8
  %2 = load %"class.std::_Sp_counted_base"** %1
  %3 = getelementptr inbounds %"class.std::_Sp_counted_base"* %2, i32 0, i32 1
  call void @_ZN9__gnu_cxxL21__atomic_add_dispatchEPii(i32* %3, i32 1)
  ret void
}

; Function Attrs: inlinehint uwtable
define internal void @_ZN9__gnu_cxxL21__atomic_add_dispatchEPii(i32* %__mem, i32 %__val) #6 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  store i32* %__mem, i32** %1, align 8
  store i32 %__val, i32* %2, align 4
  %3 = call i32 @_ZL18__gthread_active_pv()
  %4 = icmp ne i32 %3, 0
  br i1 %4, label %5, label %8

; <label>:5                                       ; preds = %0
  %6 = load i32** %1, align 8
  %7 = load i32* %2, align 4
  call void @_ZN9__gnu_cxxL12__atomic_addEPVii(i32* %6, i32 %7)
  br label %11

; <label>:8                                       ; preds = %0
  %9 = load i32** %1, align 8
  %10 = load i32* %2, align 4
  call void @_ZN9__gnu_cxxL19__atomic_add_singleEPii(i32* %9, i32 %10)
  br label %11

; <label>:11                                      ; preds = %8, %5
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZL18__gthread_active_pv() #5 {
  %1 = load i8** @_ZZL18__gthread_active_pvE20__gthread_active_ptr, align 8
  %2 = icmp ne i8* %1, null
  %3 = zext i1 %2 to i32
  ret i32 %3
}

; Function Attrs: inlinehint nounwind uwtable
define internal void @_ZN9__gnu_cxxL12__atomic_addEPVii(i32* %__mem, i32 %__val) #5 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32* %__mem, i32** %1, align 8
  store i32 %__val, i32* %2, align 4
  %5 = load i32** %1, align 8
  %6 = load i32* %2, align 4
  store i32 %6, i32* %3
  %7 = load i32* %3, align 4
  %8 = atomicrmw volatile add i32* %5, i32 %7 acq_rel
  store i32 %8, i32* %4, align 4
  %9 = load i32* %4, align 4
  ret void
}

; Function Attrs: inlinehint nounwind uwtable
define internal void @_ZN9__gnu_cxxL19__atomic_add_singleEPii(i32* %__mem, i32 %__val) #5 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  store i32* %__mem, i32** %1, align 8
  store i32 %__val, i32* %2, align 4
  %3 = load i32* %2, align 4
  %4 = load i32** %1, align 8
  %5 = load i32* %4, align 4
  %6 = add nsw i32 %5, %3
  store i32 %6, i32* %4, align 4
  ret void
}

; Function Attrs: nounwind
declare extern_weak i32 @__pthread_key_create(i32*, void (i8*)*) #1

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt12__shared_ptrI6lvalueLN9__gnu_cxx12_Lock_policyE2EED2Ev(%"class.std::__shared_ptr"* %this) unnamed_addr #4 align 2 {
  %1 = alloca %"class.std::__shared_ptr"*, align 8
  store %"class.std::__shared_ptr"* %this, %"class.std::__shared_ptr"** %1, align 8
  %2 = load %"class.std::__shared_ptr"** %1
  %3 = getelementptr inbounds %"class.std::__shared_ptr"* %2, i32 0, i32 1
  call void @_ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EED2Ev(%"class.std::__shared_count"* %3) #2
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EED2Ev(%"class.std::__shared_count"* %this) unnamed_addr #4 align 2 {
  %1 = alloca %"class.std::__shared_count"*, align 8
  store %"class.std::__shared_count"* %this, %"class.std::__shared_count"** %1, align 8
  %2 = load %"class.std::__shared_count"** %1
  %3 = getelementptr inbounds %"class.std::__shared_count"* %2, i32 0, i32 0
  %4 = load %"class.std::_Sp_counted_base"** %3, align 8
  %5 = icmp ne %"class.std::_Sp_counted_base"* %4, null
  br i1 %5, label %6, label %9

; <label>:6                                       ; preds = %0
  %7 = getelementptr inbounds %"class.std::__shared_count"* %2, i32 0, i32 0
  %8 = load %"class.std::_Sp_counted_base"** %7, align 8
  call void @_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv(%"class.std::_Sp_counted_base"* %8) #2
  br label %9

; <label>:9                                       ; preds = %6, %0
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt16_Sp_counted_baseILN9__gnu_cxx12_Lock_policyE2EE10_M_releaseEv(%"class.std::_Sp_counted_base"* %this) #4 align 2 {
  %1 = alloca %"class.std::_Sp_counted_base"*, align 8
  store %"class.std::_Sp_counted_base"* %this, %"class.std::_Sp_counted_base"** %1, align 8
  %2 = load %"class.std::_Sp_counted_base"** %1
  %3 = getelementptr inbounds %"class.std::_Sp_counted_base"* %2, i32 0, i32 1
  %4 = invoke i32 @_ZN9__gnu_cxxL27__exchange_and_add_dispatchEPii(i32* %3, i32 -1)
          to label %5 unwind label %23

; <label>:5                                       ; preds = %0
  %6 = icmp eq i32 %4, 1
  br i1 %6, label %7, label %22

; <label>:7                                       ; preds = %5
  %8 = bitcast %"class.std::_Sp_counted_base"* %2 to void (%"class.std::_Sp_counted_base"*)***
  %9 = load void (%"class.std::_Sp_counted_base"*)*** %8
  %10 = getelementptr inbounds void (%"class.std::_Sp_counted_base"*)** %9, i64 2
  %11 = load void (%"class.std::_Sp_counted_base"*)** %10
  call void %11(%"class.std::_Sp_counted_base"* %2) #2
  %12 = getelementptr inbounds %"class.std::_Sp_counted_base"* %2, i32 0, i32 2
  %13 = invoke i32 @_ZN9__gnu_cxxL27__exchange_and_add_dispatchEPii(i32* %12, i32 -1)
          to label %14 unwind label %23

; <label>:14                                      ; preds = %7
  %15 = icmp eq i32 %13, 1
  br i1 %15, label %16, label %21

; <label>:16                                      ; preds = %14
  %17 = bitcast %"class.std::_Sp_counted_base"* %2 to void (%"class.std::_Sp_counted_base"*)***
  %18 = load void (%"class.std::_Sp_counted_base"*)*** %17
  %19 = getelementptr inbounds void (%"class.std::_Sp_counted_base"*)** %18, i64 3
  %20 = load void (%"class.std::_Sp_counted_base"*)** %19
  call void %20(%"class.std::_Sp_counted_base"* %2) #2
  br label %21

; <label>:21                                      ; preds = %16, %14
  br label %22

; <label>:22                                      ; preds = %21, %5
  ret void

; <label>:23                                      ; preds = %7, %0
  %24 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %25 = extractvalue { i8*, i32 } %24, 0
  call void @__clang_call_terminate(i8* %25) #9
  unreachable
}

; Function Attrs: inlinehint uwtable
define internal i32 @_ZN9__gnu_cxxL27__exchange_and_add_dispatchEPii(i32* %__mem, i32 %__val) #6 {
  %1 = alloca i32, align 4
  %2 = alloca i32*, align 8
  %3 = alloca i32, align 4
  store i32* %__mem, i32** %2, align 8
  store i32 %__val, i32* %3, align 4
  %4 = call i32 @_ZL18__gthread_active_pv()
  %5 = icmp ne i32 %4, 0
  br i1 %5, label %6, label %10

; <label>:6                                       ; preds = %0
  %7 = load i32** %2, align 8
  %8 = load i32* %3, align 4
  %9 = call i32 @_ZN9__gnu_cxxL18__exchange_and_addEPVii(i32* %7, i32 %8)
  store i32 %9, i32* %1
  br label %14

; <label>:10                                      ; preds = %0
  %11 = load i32** %2, align 8
  %12 = load i32* %3, align 4
  %13 = call i32 @_ZN9__gnu_cxxL25__exchange_and_add_singleEPii(i32* %11, i32 %12)
  store i32 %13, i32* %1
  br label %14

; <label>:14                                      ; preds = %10, %6
  %15 = load i32* %1
  ret i32 %15
}

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZN9__gnu_cxxL18__exchange_and_addEPVii(i32* %__mem, i32 %__val) #5 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32* %__mem, i32** %1, align 8
  store i32 %__val, i32* %2, align 4
  %5 = load i32** %1, align 8
  %6 = load i32* %2, align 4
  store i32 %6, i32* %3
  %7 = load i32* %3, align 4
  %8 = atomicrmw volatile add i32* %5, i32 %7 acq_rel
  store i32 %8, i32* %4, align 4
  %9 = load i32* %4, align 4
  ret i32 %9
}

; Function Attrs: inlinehint nounwind uwtable
define internal i32 @_ZN9__gnu_cxxL25__exchange_and_add_singleEPii(i32* %__mem, i32 %__val) #5 {
  %1 = alloca i32*, align 8
  %2 = alloca i32, align 4
  %__result = alloca i32, align 4
  store i32* %__mem, i32** %1, align 8
  store i32 %__val, i32* %2, align 4
  %3 = load i32** %1, align 8
  %4 = load i32* %3, align 4
  store i32 %4, i32* %__result, align 4
  %5 = load i32* %2, align 4
  %6 = load i32** %1, align 8
  %7 = load i32* %6, align 4
  %8 = add nsw i32 %7, %5
  store i32 %8, i32* %6, align 4
  %9 = load i32* %__result, align 4
  ret i32 %9
}

; Function Attrs: uwtable
define linkonce_odr void @_ZNSt6vectorISt10shared_ptrI6lvalueESaIS2_EE12emplace_backIJS2_EEEvDpOT_(%"class.std::vector"* %this, %"class.std::shared_ptr"* dereferenceable(16) %__args) #3 align 2 {
  %1 = alloca %"class.std::vector"*, align 8
  %2 = alloca %"class.std::shared_ptr"*, align 8
  store %"class.std::vector"* %this, %"class.std::vector"** %1, align 8
  store %"class.std::shared_ptr"* %__args, %"class.std::shared_ptr"** %2, align 8
  %3 = load %"class.std::vector"** %1
  %4 = bitcast %"class.std::vector"* %3 to %"struct.std::_Vector_base"*
  %5 = getelementptr inbounds %"struct.std::_Vector_base"* %4, i32 0, i32 0
  %6 = getelementptr inbounds %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %5, i32 0, i32 1
  %7 = load %"class.std::shared_ptr"** %6, align 8
  %8 = bitcast %"class.std::vector"* %3 to %"struct.std::_Vector_base"*
  %9 = getelementptr inbounds %"struct.std::_Vector_base"* %8, i32 0, i32 0
  %10 = getelementptr inbounds %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %9, i32 0, i32 2
  %11 = load %"class.std::shared_ptr"** %10, align 8
  %12 = icmp ne %"class.std::shared_ptr"* %7, %11
  br i1 %12, label %13, label %28

; <label>:13                                      ; preds = %0
  %14 = bitcast %"class.std::vector"* %3 to %"struct.std::_Vector_base"*
  %15 = getelementptr inbounds %"struct.std::_Vector_base"* %14, i32 0, i32 0
  %16 = bitcast %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %15 to %"class.std::allocator.6"*
  %17 = bitcast %"class.std::vector"* %3 to %"struct.std::_Vector_base"*
  %18 = getelementptr inbounds %"struct.std::_Vector_base"* %17, i32 0, i32 0
  %19 = getelementptr inbounds %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %18, i32 0, i32 1
  %20 = load %"class.std::shared_ptr"** %19, align 8
  %21 = load %"class.std::shared_ptr"** %2, align 8
  %22 = call dereferenceable(16) %"class.std::shared_ptr"* @_ZSt7forwardISt10shared_ptrI6lvalueEEOT_RNSt16remove_referenceIS3_E4typeE(%"class.std::shared_ptr"* dereferenceable(16) %21) #2
  call void @_ZNSt16allocator_traitsISaISt10shared_ptrI6lvalueEEE9constructIS2_JS2_EEEDTcl12_S_constructfp_fp0_spclsr3stdE7forwardIT0_Efp1_EEERS3_PT_DpOS6_(%"class.std::allocator.6"* dereferenceable(1) %16, %"class.std::shared_ptr"* %20, %"class.std::shared_ptr"* dereferenceable(16) %22)
  %23 = bitcast %"class.std::vector"* %3 to %"struct.std::_Vector_base"*
  %24 = getelementptr inbounds %"struct.std::_Vector_base"* %23, i32 0, i32 0
  %25 = getelementptr inbounds %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %24, i32 0, i32 1
  %26 = load %"class.std::shared_ptr"** %25, align 8
  %27 = getelementptr inbounds %"class.std::shared_ptr"* %26, i32 1
  store %"class.std::shared_ptr"* %27, %"class.std::shared_ptr"** %25, align 8
  br label %31

; <label>:28                                      ; preds = %0
  %29 = load %"class.std::shared_ptr"** %2, align 8
  %30 = call dereferenceable(16) %"class.std::shared_ptr"* @_ZSt7forwardISt10shared_ptrI6lvalueEEOT_RNSt16remove_referenceIS3_E4typeE(%"class.std::shared_ptr"* dereferenceable(16) %29) #2
  call void @_ZNSt6vectorISt10shared_ptrI6lvalueESaIS2_EE19_M_emplace_back_auxIJS2_EEEvDpOT_(%"class.std::vector"* %3, %"class.std::shared_ptr"* dereferenceable(16) %30)
  br label %31

; <label>:31                                      ; preds = %28, %13
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(16) %"class.std::shared_ptr"* @_ZSt4moveIRSt10shared_ptrI6lvalueEEONSt16remove_referenceIT_E4typeEOS5_(%"class.std::shared_ptr"* dereferenceable(16) %__t) #4 {
  %1 = alloca %"class.std::shared_ptr"*, align 8
  store %"class.std::shared_ptr"* %__t, %"class.std::shared_ptr"** %1, align 8
  %2 = load %"class.std::shared_ptr"** %1, align 8
  ret %"class.std::shared_ptr"* %2
}

; Function Attrs: uwtable
define linkonce_odr void @_ZNSt16allocator_traitsISaISt10shared_ptrI6lvalueEEE9constructIS2_JS2_EEEDTcl12_S_constructfp_fp0_spclsr3stdE7forwardIT0_Efp1_EEERS3_PT_DpOS6_(%"class.std::allocator.6"* dereferenceable(1) %__a, %"class.std::shared_ptr"* %__p, %"class.std::shared_ptr"* dereferenceable(16) %__args) #3 align 2 {
  %1 = alloca %"class.std::allocator.6"*, align 8
  %2 = alloca %"class.std::shared_ptr"*, align 8
  %3 = alloca %"class.std::shared_ptr"*, align 8
  store %"class.std::allocator.6"* %__a, %"class.std::allocator.6"** %1, align 8
  store %"class.std::shared_ptr"* %__p, %"class.std::shared_ptr"** %2, align 8
  store %"class.std::shared_ptr"* %__args, %"class.std::shared_ptr"** %3, align 8
  %4 = load %"class.std::allocator.6"** %1, align 8
  %5 = load %"class.std::shared_ptr"** %2, align 8
  %6 = load %"class.std::shared_ptr"** %3, align 8
  %7 = call dereferenceable(16) %"class.std::shared_ptr"* @_ZSt7forwardISt10shared_ptrI6lvalueEEOT_RNSt16remove_referenceIS3_E4typeE(%"class.std::shared_ptr"* dereferenceable(16) %6) #2
  call void @_ZNSt16allocator_traitsISaISt10shared_ptrI6lvalueEEE12_S_constructIS2_JS2_EEENSt9enable_ifIXsr6__and_INS4_18__construct_helperIT_JDpT0_EE4typeEEE5valueEvE4typeERS3_PS8_DpOS9_(%"class.std::allocator.6"* dereferenceable(1) %4, %"class.std::shared_ptr"* %5, %"class.std::shared_ptr"* dereferenceable(16) %7)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(16) %"class.std::shared_ptr"* @_ZSt7forwardISt10shared_ptrI6lvalueEEOT_RNSt16remove_referenceIS3_E4typeE(%"class.std::shared_ptr"* dereferenceable(16) %__t) #4 {
  %1 = alloca %"class.std::shared_ptr"*, align 8
  store %"class.std::shared_ptr"* %__t, %"class.std::shared_ptr"** %1, align 8
  %2 = load %"class.std::shared_ptr"** %1, align 8
  ret %"class.std::shared_ptr"* %2
}

; Function Attrs: uwtable
define linkonce_odr void @_ZNSt6vectorISt10shared_ptrI6lvalueESaIS2_EE19_M_emplace_back_auxIJS2_EEEvDpOT_(%"class.std::vector"* %this, %"class.std::shared_ptr"* dereferenceable(16) %__args) #3 align 2 {
  %1 = alloca %"class.std::vector"*, align 8
  %2 = alloca %"class.std::shared_ptr"*, align 8
  %__len = alloca i64, align 8
  %__new_start = alloca %"class.std::shared_ptr"*, align 8
  %__new_finish = alloca %"class.std::shared_ptr"*, align 8
  %3 = alloca i8*
  %4 = alloca i32
  store %"class.std::vector"* %this, %"class.std::vector"** %1, align 8
  store %"class.std::shared_ptr"* %__args, %"class.std::shared_ptr"** %2, align 8
  %5 = load %"class.std::vector"** %1
  %6 = call i64 @_ZNKSt6vectorISt10shared_ptrI6lvalueESaIS2_EE12_M_check_lenEmPKc(%"class.std::vector"* %5, i64 1, i8* getelementptr inbounds ([28 x i8]* @.str6, i32 0, i32 0))
  store i64 %6, i64* %__len, align 8
  %7 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %8 = load i64* %__len, align 8
  %9 = call %"class.std::shared_ptr"* @_ZNSt12_Vector_baseISt10shared_ptrI6lvalueESaIS2_EE11_M_allocateEm(%"struct.std::_Vector_base"* %7, i64 %8)
  store %"class.std::shared_ptr"* %9, %"class.std::shared_ptr"** %__new_start, align 8
  %10 = load %"class.std::shared_ptr"** %__new_start, align 8
  store %"class.std::shared_ptr"* %10, %"class.std::shared_ptr"** %__new_finish, align 8
  %11 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %12 = getelementptr inbounds %"struct.std::_Vector_base"* %11, i32 0, i32 0
  %13 = bitcast %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %12 to %"class.std::allocator.6"*
  %14 = load %"class.std::shared_ptr"** %__new_start, align 8
  %15 = call i64 @_ZNKSt6vectorISt10shared_ptrI6lvalueESaIS2_EE4sizeEv(%"class.std::vector"* %5) #2
  %16 = getelementptr inbounds %"class.std::shared_ptr"* %14, i64 %15
  %17 = load %"class.std::shared_ptr"** %2, align 8
  %18 = call dereferenceable(16) %"class.std::shared_ptr"* @_ZSt7forwardISt10shared_ptrI6lvalueEEOT_RNSt16remove_referenceIS3_E4typeE(%"class.std::shared_ptr"* dereferenceable(16) %17) #2
  invoke void @_ZNSt16allocator_traitsISaISt10shared_ptrI6lvalueEEE9constructIS2_JS2_EEEDTcl12_S_constructfp_fp0_spclsr3stdE7forwardIT0_Efp1_EEERS3_PT_DpOS6_(%"class.std::allocator.6"* dereferenceable(1) %13, %"class.std::shared_ptr"* %16, %"class.std::shared_ptr"* dereferenceable(16) %18)
          to label %19 unwind label %35

; <label>:19                                      ; preds = %0
  store %"class.std::shared_ptr"* null, %"class.std::shared_ptr"** %__new_finish, align 8
  %20 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %21 = getelementptr inbounds %"struct.std::_Vector_base"* %20, i32 0, i32 0
  %22 = getelementptr inbounds %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %21, i32 0, i32 0
  %23 = load %"class.std::shared_ptr"** %22, align 8
  %24 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %25 = getelementptr inbounds %"struct.std::_Vector_base"* %24, i32 0, i32 0
  %26 = getelementptr inbounds %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %25, i32 0, i32 1
  %27 = load %"class.std::shared_ptr"** %26, align 8
  %28 = load %"class.std::shared_ptr"** %__new_start, align 8
  %29 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %30 = call dereferenceable(1) %"class.std::allocator.6"* @_ZNSt12_Vector_baseISt10shared_ptrI6lvalueESaIS2_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base"* %29) #2
  %31 = invoke %"class.std::shared_ptr"* @_ZSt34__uninitialized_move_if_noexcept_aIPSt10shared_ptrI6lvalueES3_SaIS2_EET0_T_S6_S5_RT1_(%"class.std::shared_ptr"* %23, %"class.std::shared_ptr"* %27, %"class.std::shared_ptr"* %28, %"class.std::allocator.6"* dereferenceable(1) %30)
          to label %32 unwind label %35

; <label>:32                                      ; preds = %19
  store %"class.std::shared_ptr"* %31, %"class.std::shared_ptr"** %__new_finish, align 8
  %33 = load %"class.std::shared_ptr"** %__new_finish, align 8
  %34 = getelementptr inbounds %"class.std::shared_ptr"* %33, i32 1
  store %"class.std::shared_ptr"* %34, %"class.std::shared_ptr"** %__new_finish, align 8
  br label %68

; <label>:35                                      ; preds = %19, %0
  %36 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %37 = extractvalue { i8*, i32 } %36, 0
  store i8* %37, i8** %3
  %38 = extractvalue { i8*, i32 } %36, 1
  store i32 %38, i32* %4
  br label %39

; <label>:39                                      ; preds = %35
  %40 = load i8** %3
  %41 = call i8* @__cxa_begin_catch(i8* %40) #2
  %42 = load %"class.std::shared_ptr"** %__new_finish, align 8
  %43 = icmp ne %"class.std::shared_ptr"* %42, null
  br i1 %43, label %56, label %44

; <label>:44                                      ; preds = %39
  %45 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %46 = getelementptr inbounds %"struct.std::_Vector_base"* %45, i32 0, i32 0
  %47 = bitcast %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %46 to %"class.std::allocator.6"*
  %48 = load %"class.std::shared_ptr"** %__new_start, align 8
  %49 = call i64 @_ZNKSt6vectorISt10shared_ptrI6lvalueESaIS2_EE4sizeEv(%"class.std::vector"* %5) #2
  %50 = getelementptr inbounds %"class.std::shared_ptr"* %48, i64 %49
  invoke void @_ZNSt16allocator_traitsISaISt10shared_ptrI6lvalueEEE7destroyIS2_EEvRS3_PT_(%"class.std::allocator.6"* dereferenceable(1) %47, %"class.std::shared_ptr"* %50)
          to label %51 unwind label %52

; <label>:51                                      ; preds = %44
  br label %62

; <label>:52                                      ; preds = %66, %62, %56, %44
  %53 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %54 = extractvalue { i8*, i32 } %53, 0
  store i8* %54, i8** %3
  %55 = extractvalue { i8*, i32 } %53, 1
  store i32 %55, i32* %4
  invoke void @__cxa_end_catch()
          to label %67 unwind label %115

; <label>:56                                      ; preds = %39
  %57 = load %"class.std::shared_ptr"** %__new_start, align 8
  %58 = load %"class.std::shared_ptr"** %__new_finish, align 8
  %59 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %60 = call dereferenceable(1) %"class.std::allocator.6"* @_ZNSt12_Vector_baseISt10shared_ptrI6lvalueESaIS2_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base"* %59) #2
  invoke void @_ZSt8_DestroyIPSt10shared_ptrI6lvalueES2_EvT_S4_RSaIT0_E(%"class.std::shared_ptr"* %57, %"class.std::shared_ptr"* %58, %"class.std::allocator.6"* dereferenceable(1) %60)
          to label %61 unwind label %52

; <label>:61                                      ; preds = %56
  br label %62

; <label>:62                                      ; preds = %61, %51
  %63 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %64 = load %"class.std::shared_ptr"** %__new_start, align 8
  %65 = load i64* %__len, align 8
  invoke void @_ZNSt12_Vector_baseISt10shared_ptrI6lvalueESaIS2_EE13_M_deallocateEPS2_m(%"struct.std::_Vector_base"* %63, %"class.std::shared_ptr"* %64, i64 %65)
          to label %66 unwind label %52

; <label>:66                                      ; preds = %62
  invoke void @__cxa_rethrow() #12
          to label %118 unwind label %52

; <label>:67                                      ; preds = %52
  br label %110

; <label>:68                                      ; preds = %32
  %69 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %70 = getelementptr inbounds %"struct.std::_Vector_base"* %69, i32 0, i32 0
  %71 = getelementptr inbounds %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %70, i32 0, i32 0
  %72 = load %"class.std::shared_ptr"** %71, align 8
  %73 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %74 = getelementptr inbounds %"struct.std::_Vector_base"* %73, i32 0, i32 0
  %75 = getelementptr inbounds %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %74, i32 0, i32 1
  %76 = load %"class.std::shared_ptr"** %75, align 8
  %77 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %78 = call dereferenceable(1) %"class.std::allocator.6"* @_ZNSt12_Vector_baseISt10shared_ptrI6lvalueESaIS2_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base"* %77) #2
  call void @_ZSt8_DestroyIPSt10shared_ptrI6lvalueES2_EvT_S4_RSaIT0_E(%"class.std::shared_ptr"* %72, %"class.std::shared_ptr"* %76, %"class.std::allocator.6"* dereferenceable(1) %78)
  %79 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %80 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %81 = getelementptr inbounds %"struct.std::_Vector_base"* %80, i32 0, i32 0
  %82 = getelementptr inbounds %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %81, i32 0, i32 0
  %83 = load %"class.std::shared_ptr"** %82, align 8
  %84 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %85 = getelementptr inbounds %"struct.std::_Vector_base"* %84, i32 0, i32 0
  %86 = getelementptr inbounds %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %85, i32 0, i32 2
  %87 = load %"class.std::shared_ptr"** %86, align 8
  %88 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %89 = getelementptr inbounds %"struct.std::_Vector_base"* %88, i32 0, i32 0
  %90 = getelementptr inbounds %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %89, i32 0, i32 0
  %91 = load %"class.std::shared_ptr"** %90, align 8
  %92 = ptrtoint %"class.std::shared_ptr"* %87 to i64
  %93 = ptrtoint %"class.std::shared_ptr"* %91 to i64
  %94 = sub i64 %92, %93
  %95 = sdiv exact i64 %94, 16
  call void @_ZNSt12_Vector_baseISt10shared_ptrI6lvalueESaIS2_EE13_M_deallocateEPS2_m(%"struct.std::_Vector_base"* %79, %"class.std::shared_ptr"* %83, i64 %95)
  %96 = load %"class.std::shared_ptr"** %__new_start, align 8
  %97 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %98 = getelementptr inbounds %"struct.std::_Vector_base"* %97, i32 0, i32 0
  %99 = getelementptr inbounds %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %98, i32 0, i32 0
  store %"class.std::shared_ptr"* %96, %"class.std::shared_ptr"** %99, align 8
  %100 = load %"class.std::shared_ptr"** %__new_finish, align 8
  %101 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %102 = getelementptr inbounds %"struct.std::_Vector_base"* %101, i32 0, i32 0
  %103 = getelementptr inbounds %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %102, i32 0, i32 1
  store %"class.std::shared_ptr"* %100, %"class.std::shared_ptr"** %103, align 8
  %104 = load %"class.std::shared_ptr"** %__new_start, align 8
  %105 = load i64* %__len, align 8
  %106 = getelementptr inbounds %"class.std::shared_ptr"* %104, i64 %105
  %107 = bitcast %"class.std::vector"* %5 to %"struct.std::_Vector_base"*
  %108 = getelementptr inbounds %"struct.std::_Vector_base"* %107, i32 0, i32 0
  %109 = getelementptr inbounds %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %108, i32 0, i32 2
  store %"class.std::shared_ptr"* %106, %"class.std::shared_ptr"** %109, align 8
  ret void

; <label>:110                                     ; preds = %67
  %111 = load i8** %3
  %112 = load i32* %4
  %113 = insertvalue { i8*, i32 } undef, i8* %111, 0
  %114 = insertvalue { i8*, i32 } %113, i32 %112, 1
  resume { i8*, i32 } %114

; <label>:115                                     ; preds = %52
  %116 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %117 = extractvalue { i8*, i32 } %116, 0
  call void @__clang_call_terminate(i8* %117) #9
  unreachable

; <label>:118                                     ; preds = %66
  unreachable
}

; Function Attrs: uwtable
define linkonce_odr i64 @_ZNKSt6vectorISt10shared_ptrI6lvalueESaIS2_EE12_M_check_lenEmPKc(%"class.std::vector"* %this, i64 %__n, i8* %__s) #3 align 2 {
  %1 = alloca %"class.std::vector"*, align 8
  %2 = alloca i64, align 8
  %3 = alloca i8*, align 8
  %__len = alloca i64, align 8
  %4 = alloca i64, align 8
  store %"class.std::vector"* %this, %"class.std::vector"** %1, align 8
  store i64 %__n, i64* %2, align 8
  store i8* %__s, i8** %3, align 8
  %5 = load %"class.std::vector"** %1
  %6 = call i64 @_ZNKSt6vectorISt10shared_ptrI6lvalueESaIS2_EE8max_sizeEv(%"class.std::vector"* %5) #2
  %7 = call i64 @_ZNKSt6vectorISt10shared_ptrI6lvalueESaIS2_EE4sizeEv(%"class.std::vector"* %5) #2
  %8 = sub i64 %6, %7
  %9 = load i64* %2, align 8
  %10 = icmp ult i64 %8, %9
  br i1 %10, label %11, label %13

; <label>:11                                      ; preds = %0
  %12 = load i8** %3, align 8
  call void @_ZSt20__throw_length_errorPKc(i8* %12) #12
  unreachable

; <label>:13                                      ; preds = %0
  %14 = call i64 @_ZNKSt6vectorISt10shared_ptrI6lvalueESaIS2_EE4sizeEv(%"class.std::vector"* %5) #2
  %15 = call i64 @_ZNKSt6vectorISt10shared_ptrI6lvalueESaIS2_EE4sizeEv(%"class.std::vector"* %5) #2
  store i64 %15, i64* %4
  %16 = call dereferenceable(8) i64* @_ZSt3maxImERKT_S2_S2_(i64* dereferenceable(8) %4, i64* dereferenceable(8) %2)
  %17 = load i64* %16
  %18 = add i64 %14, %17
  store i64 %18, i64* %__len, align 8
  %19 = load i64* %__len, align 8
  %20 = call i64 @_ZNKSt6vectorISt10shared_ptrI6lvalueESaIS2_EE4sizeEv(%"class.std::vector"* %5) #2
  %21 = icmp ult i64 %19, %20
  br i1 %21, label %26, label %22

; <label>:22                                      ; preds = %13
  %23 = load i64* %__len, align 8
  %24 = call i64 @_ZNKSt6vectorISt10shared_ptrI6lvalueESaIS2_EE8max_sizeEv(%"class.std::vector"* %5) #2
  %25 = icmp ugt i64 %23, %24
  br i1 %25, label %26, label %28

; <label>:26                                      ; preds = %22, %13
  %27 = call i64 @_ZNKSt6vectorISt10shared_ptrI6lvalueESaIS2_EE8max_sizeEv(%"class.std::vector"* %5) #2
  br label %30

; <label>:28                                      ; preds = %22
  %29 = load i64* %__len, align 8
  br label %30

; <label>:30                                      ; preds = %28, %26
  %31 = phi i64 [ %27, %26 ], [ %29, %28 ]
  ret i64 %31
}

; Function Attrs: uwtable
define linkonce_odr %"class.std::shared_ptr"* @_ZNSt12_Vector_baseISt10shared_ptrI6lvalueESaIS2_EE11_M_allocateEm(%"struct.std::_Vector_base"* %this, i64 %__n) #3 align 2 {
  %1 = alloca %"struct.std::_Vector_base"*, align 8
  %2 = alloca i64, align 8
  store %"struct.std::_Vector_base"* %this, %"struct.std::_Vector_base"** %1, align 8
  store i64 %__n, i64* %2, align 8
  %3 = load %"struct.std::_Vector_base"** %1
  %4 = load i64* %2, align 8
  %5 = icmp ne i64 %4, 0
  br i1 %5, label %6, label %11

; <label>:6                                       ; preds = %0
  %7 = getelementptr inbounds %"struct.std::_Vector_base"* %3, i32 0, i32 0
  %8 = bitcast %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %7 to %"class.std::allocator.6"*
  %9 = load i64* %2, align 8
  %10 = call %"class.std::shared_ptr"* @_ZNSt16allocator_traitsISaISt10shared_ptrI6lvalueEEE8allocateERS3_m(%"class.std::allocator.6"* dereferenceable(1) %8, i64 %9)
  br label %12

; <label>:11                                      ; preds = %0
  br label %12

; <label>:12                                      ; preds = %11, %6
  %13 = phi %"class.std::shared_ptr"* [ %10, %6 ], [ null, %11 ]
  ret %"class.std::shared_ptr"* %13
}

; Function Attrs: inlinehint uwtable
define linkonce_odr %"class.std::shared_ptr"* @_ZSt34__uninitialized_move_if_noexcept_aIPSt10shared_ptrI6lvalueES3_SaIS2_EET0_T_S6_S5_RT1_(%"class.std::shared_ptr"* %__first, %"class.std::shared_ptr"* %__last, %"class.std::shared_ptr"* %__result, %"class.std::allocator.6"* dereferenceable(1) %__alloc) #6 {
  %1 = alloca %"class.std::shared_ptr"*, align 8
  %2 = alloca %"class.std::shared_ptr"*, align 8
  %3 = alloca %"class.std::shared_ptr"*, align 8
  %4 = alloca %"class.std::allocator.6"*, align 8
  %5 = alloca %"class.std::move_iterator", align 8
  %6 = alloca %"class.std::move_iterator", align 8
  store %"class.std::shared_ptr"* %__first, %"class.std::shared_ptr"** %1, align 8
  store %"class.std::shared_ptr"* %__last, %"class.std::shared_ptr"** %2, align 8
  store %"class.std::shared_ptr"* %__result, %"class.std::shared_ptr"** %3, align 8
  store %"class.std::allocator.6"* %__alloc, %"class.std::allocator.6"** %4, align 8
  %7 = load %"class.std::shared_ptr"** %1, align 8
  %8 = call %"class.std::shared_ptr"* @_ZSt32__make_move_if_noexcept_iteratorIPSt10shared_ptrI6lvalueESt13move_iteratorIS3_EET0_T_(%"class.std::shared_ptr"* %7)
  %9 = getelementptr %"class.std::move_iterator"* %5, i32 0, i32 0
  store %"class.std::shared_ptr"* %8, %"class.std::shared_ptr"** %9
  %10 = load %"class.std::shared_ptr"** %2, align 8
  %11 = call %"class.std::shared_ptr"* @_ZSt32__make_move_if_noexcept_iteratorIPSt10shared_ptrI6lvalueESt13move_iteratorIS3_EET0_T_(%"class.std::shared_ptr"* %10)
  %12 = getelementptr %"class.std::move_iterator"* %6, i32 0, i32 0
  store %"class.std::shared_ptr"* %11, %"class.std::shared_ptr"** %12
  %13 = load %"class.std::shared_ptr"** %3, align 8
  %14 = load %"class.std::allocator.6"** %4, align 8
  %15 = getelementptr %"class.std::move_iterator"* %5, i32 0, i32 0
  %16 = load %"class.std::shared_ptr"** %15
  %17 = getelementptr %"class.std::move_iterator"* %6, i32 0, i32 0
  %18 = load %"class.std::shared_ptr"** %17
  %19 = call %"class.std::shared_ptr"* @_ZSt22__uninitialized_copy_aISt13move_iteratorIPSt10shared_ptrI6lvalueEES4_S3_ET0_T_S7_S6_RSaIT1_E(%"class.std::shared_ptr"* %16, %"class.std::shared_ptr"* %18, %"class.std::shared_ptr"* %13, %"class.std::allocator.6"* dereferenceable(1) %14)
  ret %"class.std::shared_ptr"* %19
}

; Function Attrs: uwtable
define linkonce_odr void @_ZNSt16allocator_traitsISaISt10shared_ptrI6lvalueEEE7destroyIS2_EEvRS3_PT_(%"class.std::allocator.6"* dereferenceable(1) %__a, %"class.std::shared_ptr"* %__p) #3 align 2 {
  %1 = alloca %"class.std::allocator.6"*, align 8
  %2 = alloca %"class.std::shared_ptr"*, align 8
  store %"class.std::allocator.6"* %__a, %"class.std::allocator.6"** %1, align 8
  store %"class.std::shared_ptr"* %__p, %"class.std::shared_ptr"** %2, align 8
  %3 = load %"class.std::allocator.6"** %1, align 8
  %4 = load %"class.std::shared_ptr"** %2, align 8
  call void @_ZNSt16allocator_traitsISaISt10shared_ptrI6lvalueEEE10_S_destroyIS2_EENSt9enable_ifIXsr6__and_INS4_16__destroy_helperIT_E4typeEEE5valueEvE4typeERS3_PS8_(%"class.std::allocator.6"* dereferenceable(1) %3, %"class.std::shared_ptr"* %4)
  ret void
}

declare void @__cxa_rethrow()

declare void @__cxa_end_catch()

; Function Attrs: uwtable
define linkonce_odr void @_ZNSt16allocator_traitsISaISt10shared_ptrI6lvalueEEE10_S_destroyIS2_EENSt9enable_ifIXsr6__and_INS4_16__destroy_helperIT_E4typeEEE5valueEvE4typeERS3_PS8_(%"class.std::allocator.6"* dereferenceable(1) %__a, %"class.std::shared_ptr"* %__p) #3 align 2 {
  %1 = alloca %"class.std::allocator.6"*, align 8
  %2 = alloca %"class.std::shared_ptr"*, align 8
  store %"class.std::allocator.6"* %__a, %"class.std::allocator.6"** %1, align 8
  store %"class.std::shared_ptr"* %__p, %"class.std::shared_ptr"** %2, align 8
  %3 = load %"class.std::allocator.6"** %1, align 8
  %4 = bitcast %"class.std::allocator.6"* %3 to %"class.__gnu_cxx::new_allocator.7"*
  %5 = load %"class.std::shared_ptr"** %2, align 8
  call void @_ZN9__gnu_cxx13new_allocatorISt10shared_ptrI6lvalueEE7destroyIS3_EEvPT_(%"class.__gnu_cxx::new_allocator.7"* %4, %"class.std::shared_ptr"* %5)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx13new_allocatorISt10shared_ptrI6lvalueEE7destroyIS3_EEvPT_(%"class.__gnu_cxx::new_allocator.7"* %this, %"class.std::shared_ptr"* %__p) #4 align 2 {
  %1 = alloca %"class.__gnu_cxx::new_allocator.7"*, align 8
  %2 = alloca %"class.std::shared_ptr"*, align 8
  store %"class.__gnu_cxx::new_allocator.7"* %this, %"class.__gnu_cxx::new_allocator.7"** %1, align 8
  store %"class.std::shared_ptr"* %__p, %"class.std::shared_ptr"** %2, align 8
  %3 = load %"class.__gnu_cxx::new_allocator.7"** %1
  %4 = load %"class.std::shared_ptr"** %2, align 8
  call void @_ZNSt10shared_ptrI6lvalueED2Ev(%"class.std::shared_ptr"* %4) #2
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr %"class.std::shared_ptr"* @_ZSt22__uninitialized_copy_aISt13move_iteratorIPSt10shared_ptrI6lvalueEES4_S3_ET0_T_S7_S6_RSaIT1_E(%"class.std::shared_ptr"* %__first.coerce, %"class.std::shared_ptr"* %__last.coerce, %"class.std::shared_ptr"* %__result, %"class.std::allocator.6"* dereferenceable(1)) #6 {
  %__first = alloca %"class.std::move_iterator", align 8
  %__last = alloca %"class.std::move_iterator", align 8
  %2 = alloca %"class.std::shared_ptr"*, align 8
  %3 = alloca %"class.std::allocator.6"*, align 8
  %4 = alloca %"class.std::move_iterator", align 8
  %5 = alloca %"class.std::move_iterator", align 8
  %6 = getelementptr %"class.std::move_iterator"* %__first, i32 0, i32 0
  store %"class.std::shared_ptr"* %__first.coerce, %"class.std::shared_ptr"** %6
  %7 = getelementptr %"class.std::move_iterator"* %__last, i32 0, i32 0
  store %"class.std::shared_ptr"* %__last.coerce, %"class.std::shared_ptr"** %7
  store %"class.std::shared_ptr"* %__result, %"class.std::shared_ptr"** %2, align 8
  store %"class.std::allocator.6"* %0, %"class.std::allocator.6"** %3, align 8
  %8 = bitcast %"class.std::move_iterator"* %4 to i8*
  %9 = bitcast %"class.std::move_iterator"* %__first to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %8, i8* %9, i64 8, i32 8, i1 false)
  %10 = bitcast %"class.std::move_iterator"* %5 to i8*
  %11 = bitcast %"class.std::move_iterator"* %__last to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %10, i8* %11, i64 8, i32 8, i1 false)
  %12 = load %"class.std::shared_ptr"** %2, align 8
  %13 = getelementptr %"class.std::move_iterator"* %4, i32 0, i32 0
  %14 = load %"class.std::shared_ptr"** %13
  %15 = getelementptr %"class.std::move_iterator"* %5, i32 0, i32 0
  %16 = load %"class.std::shared_ptr"** %15
  %17 = call %"class.std::shared_ptr"* @_ZSt18uninitialized_copyISt13move_iteratorIPSt10shared_ptrI6lvalueEES4_ET0_T_S7_S6_(%"class.std::shared_ptr"* %14, %"class.std::shared_ptr"* %16, %"class.std::shared_ptr"* %12)
  ret %"class.std::shared_ptr"* %17
}

; Function Attrs: inlinehint uwtable
define linkonce_odr %"class.std::shared_ptr"* @_ZSt32__make_move_if_noexcept_iteratorIPSt10shared_ptrI6lvalueESt13move_iteratorIS3_EET0_T_(%"class.std::shared_ptr"* %__i) #6 {
  %1 = alloca %"class.std::move_iterator", align 8
  %2 = alloca %"class.std::shared_ptr"*, align 8
  store %"class.std::shared_ptr"* %__i, %"class.std::shared_ptr"** %2, align 8
  %3 = load %"class.std::shared_ptr"** %2, align 8
  call void @_ZNSt13move_iteratorIPSt10shared_ptrI6lvalueEEC2ES3_(%"class.std::move_iterator"* %1, %"class.std::shared_ptr"* %3)
  %4 = getelementptr %"class.std::move_iterator"* %1, i32 0, i32 0
  %5 = load %"class.std::shared_ptr"** %4
  ret %"class.std::shared_ptr"* %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt13move_iteratorIPSt10shared_ptrI6lvalueEEC2ES3_(%"class.std::move_iterator"* %this, %"class.std::shared_ptr"* %__i) unnamed_addr #4 align 2 {
  %1 = alloca %"class.std::move_iterator"*, align 8
  %2 = alloca %"class.std::shared_ptr"*, align 8
  store %"class.std::move_iterator"* %this, %"class.std::move_iterator"** %1, align 8
  store %"class.std::shared_ptr"* %__i, %"class.std::shared_ptr"** %2, align 8
  %3 = load %"class.std::move_iterator"** %1
  %4 = getelementptr inbounds %"class.std::move_iterator"* %3, i32 0, i32 0
  %5 = load %"class.std::shared_ptr"** %2, align 8
  store %"class.std::shared_ptr"* %5, %"class.std::shared_ptr"** %4, align 8
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr %"class.std::shared_ptr"* @_ZSt18uninitialized_copyISt13move_iteratorIPSt10shared_ptrI6lvalueEES4_ET0_T_S7_S6_(%"class.std::shared_ptr"* %__first.coerce, %"class.std::shared_ptr"* %__last.coerce, %"class.std::shared_ptr"* %__result) #6 {
  %__first = alloca %"class.std::move_iterator", align 8
  %__last = alloca %"class.std::move_iterator", align 8
  %1 = alloca %"class.std::shared_ptr"*, align 8
  %__assignable = alloca i8, align 1
  %2 = alloca %"class.std::move_iterator", align 8
  %3 = alloca %"class.std::move_iterator", align 8
  %4 = getelementptr %"class.std::move_iterator"* %__first, i32 0, i32 0
  store %"class.std::shared_ptr"* %__first.coerce, %"class.std::shared_ptr"** %4
  %5 = getelementptr %"class.std::move_iterator"* %__last, i32 0, i32 0
  store %"class.std::shared_ptr"* %__last.coerce, %"class.std::shared_ptr"** %5
  store %"class.std::shared_ptr"* %__result, %"class.std::shared_ptr"** %1, align 8
  store i8 1, i8* %__assignable, align 1
  %6 = bitcast %"class.std::move_iterator"* %2 to i8*
  %7 = bitcast %"class.std::move_iterator"* %__first to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %6, i8* %7, i64 8, i32 8, i1 false)
  %8 = bitcast %"class.std::move_iterator"* %3 to i8*
  %9 = bitcast %"class.std::move_iterator"* %__last to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %8, i8* %9, i64 8, i32 8, i1 false)
  %10 = load %"class.std::shared_ptr"** %1, align 8
  %11 = getelementptr %"class.std::move_iterator"* %2, i32 0, i32 0
  %12 = load %"class.std::shared_ptr"** %11
  %13 = getelementptr %"class.std::move_iterator"* %3, i32 0, i32 0
  %14 = load %"class.std::shared_ptr"** %13
  %15 = call %"class.std::shared_ptr"* @_ZNSt20__uninitialized_copyILb0EE13__uninit_copyISt13move_iteratorIPSt10shared_ptrI6lvalueEES6_EET0_T_S9_S8_(%"class.std::shared_ptr"* %12, %"class.std::shared_ptr"* %14, %"class.std::shared_ptr"* %10)
  ret %"class.std::shared_ptr"* %15
}

; Function Attrs: nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture, i8* nocapture readonly, i64, i32, i1) #2

; Function Attrs: uwtable
define linkonce_odr %"class.std::shared_ptr"* @_ZNSt20__uninitialized_copyILb0EE13__uninit_copyISt13move_iteratorIPSt10shared_ptrI6lvalueEES6_EET0_T_S9_S8_(%"class.std::shared_ptr"* %__first.coerce, %"class.std::shared_ptr"* %__last.coerce, %"class.std::shared_ptr"* %__result) #3 align 2 {
  %__first = alloca %"class.std::move_iterator", align 8
  %__last = alloca %"class.std::move_iterator", align 8
  %1 = alloca %"class.std::shared_ptr"*, align 8
  %__cur = alloca %"class.std::shared_ptr"*, align 8
  %2 = alloca i8*
  %3 = alloca i32
  %4 = getelementptr %"class.std::move_iterator"* %__first, i32 0, i32 0
  store %"class.std::shared_ptr"* %__first.coerce, %"class.std::shared_ptr"** %4
  %5 = getelementptr %"class.std::move_iterator"* %__last, i32 0, i32 0
  store %"class.std::shared_ptr"* %__last.coerce, %"class.std::shared_ptr"** %5
  store %"class.std::shared_ptr"* %__result, %"class.std::shared_ptr"** %1, align 8
  %6 = load %"class.std::shared_ptr"** %1, align 8
  store %"class.std::shared_ptr"* %6, %"class.std::shared_ptr"** %__cur, align 8
  br label %7

; <label>:7                                       ; preds = %18, %0
  %8 = invoke zeroext i1 @_ZStneIPSt10shared_ptrI6lvalueEEbRKSt13move_iteratorIT_ES8_(%"class.std::move_iterator"* dereferenceable(8) %__first, %"class.std::move_iterator"* dereferenceable(8) %__last)
          to label %9 unwind label %21

; <label>:9                                       ; preds = %7
  br i1 %8, label %10, label %31

; <label>:10                                      ; preds = %9
  %11 = load %"class.std::shared_ptr"** %__cur, align 8
  %12 = call %"class.std::shared_ptr"* @_ZSt11__addressofISt10shared_ptrI6lvalueEEPT_RS3_(%"class.std::shared_ptr"* dereferenceable(16) %11) #2
  %13 = invoke dereferenceable(16) %"class.std::shared_ptr"* @_ZNKSt13move_iteratorIPSt10shared_ptrI6lvalueEEdeEv(%"class.std::move_iterator"* %__first)
          to label %14 unwind label %21

; <label>:14                                      ; preds = %10
  invoke void @_ZSt10_ConstructISt10shared_ptrI6lvalueEJS2_EEvPT_DpOT0_(%"class.std::shared_ptr"* %12, %"class.std::shared_ptr"* dereferenceable(16) %13)
          to label %15 unwind label %21

; <label>:15                                      ; preds = %14
  br label %16

; <label>:16                                      ; preds = %15
  %17 = invoke dereferenceable(8) %"class.std::move_iterator"* @_ZNSt13move_iteratorIPSt10shared_ptrI6lvalueEEppEv(%"class.std::move_iterator"* %__first)
          to label %18 unwind label %21

; <label>:18                                      ; preds = %16
  %19 = load %"class.std::shared_ptr"** %__cur, align 8
  %20 = getelementptr inbounds %"class.std::shared_ptr"* %19, i32 1
  store %"class.std::shared_ptr"* %20, %"class.std::shared_ptr"** %__cur, align 8
  br label %7

; <label>:21                                      ; preds = %16, %14, %10, %7
  %22 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %23 = extractvalue { i8*, i32 } %22, 0
  store i8* %23, i8** %2
  %24 = extractvalue { i8*, i32 } %22, 1
  store i32 %24, i32* %3
  br label %25

; <label>:25                                      ; preds = %21
  %26 = load i8** %2
  %27 = call i8* @__cxa_begin_catch(i8* %26) #2
  %28 = load %"class.std::shared_ptr"** %1, align 8
  %29 = load %"class.std::shared_ptr"** %__cur, align 8
  invoke void @_ZSt8_DestroyIPSt10shared_ptrI6lvalueEEvT_S4_(%"class.std::shared_ptr"* %28, %"class.std::shared_ptr"* %29)
          to label %30 unwind label %33

; <label>:30                                      ; preds = %25
  invoke void @__cxa_rethrow() #12
          to label %47 unwind label %33

; <label>:31                                      ; preds = %9
  %32 = load %"class.std::shared_ptr"** %__cur, align 8
  ret %"class.std::shared_ptr"* %32

; <label>:33                                      ; preds = %30, %25
  %34 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          cleanup
  %35 = extractvalue { i8*, i32 } %34, 0
  store i8* %35, i8** %2
  %36 = extractvalue { i8*, i32 } %34, 1
  store i32 %36, i32* %3
  invoke void @__cxa_end_catch()
          to label %37 unwind label %44

; <label>:37                                      ; preds = %33
  br label %39
                                                  ; No predecessors!
  call void @llvm.trap()
  unreachable

; <label>:39                                      ; preds = %37
  %40 = load i8** %2
  %41 = load i32* %3
  %42 = insertvalue { i8*, i32 } undef, i8* %40, 0
  %43 = insertvalue { i8*, i32 } %42, i32 %41, 1
  resume { i8*, i32 } %43

; <label>:44                                      ; preds = %33
  %45 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %46 = extractvalue { i8*, i32 } %45, 0
  call void @__clang_call_terminate(i8* %46) #9
  unreachable

; <label>:47                                      ; preds = %30
  unreachable
}

; Function Attrs: inlinehint uwtable
define linkonce_odr zeroext i1 @_ZStneIPSt10shared_ptrI6lvalueEEbRKSt13move_iteratorIT_ES8_(%"class.std::move_iterator"* dereferenceable(8) %__x, %"class.std::move_iterator"* dereferenceable(8) %__y) #6 {
  %1 = alloca %"class.std::move_iterator"*, align 8
  %2 = alloca %"class.std::move_iterator"*, align 8
  store %"class.std::move_iterator"* %__x, %"class.std::move_iterator"** %1, align 8
  store %"class.std::move_iterator"* %__y, %"class.std::move_iterator"** %2, align 8
  %3 = load %"class.std::move_iterator"** %1, align 8
  %4 = load %"class.std::move_iterator"** %2, align 8
  %5 = call zeroext i1 @_ZSteqIPSt10shared_ptrI6lvalueEEbRKSt13move_iteratorIT_ES8_(%"class.std::move_iterator"* dereferenceable(8) %3, %"class.std::move_iterator"* dereferenceable(8) %4)
  %6 = xor i1 %5, true
  ret i1 %6
}

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr void @_ZSt10_ConstructISt10shared_ptrI6lvalueEJS2_EEvPT_DpOT0_(%"class.std::shared_ptr"* %__p, %"class.std::shared_ptr"* dereferenceable(16) %__args) #5 {
  %1 = alloca %"class.std::shared_ptr"*, align 8
  %2 = alloca %"class.std::shared_ptr"*, align 8
  store %"class.std::shared_ptr"* %__p, %"class.std::shared_ptr"** %1, align 8
  store %"class.std::shared_ptr"* %__args, %"class.std::shared_ptr"** %2, align 8
  %3 = load %"class.std::shared_ptr"** %1, align 8
  %4 = bitcast %"class.std::shared_ptr"* %3 to i8*
  %5 = icmp eq i8* %4, null
  br i1 %5, label %10, label %6

; <label>:6                                       ; preds = %0
  %7 = bitcast i8* %4 to %"class.std::shared_ptr"*
  %8 = load %"class.std::shared_ptr"** %2, align 8
  %9 = call dereferenceable(16) %"class.std::shared_ptr"* @_ZSt7forwardISt10shared_ptrI6lvalueEEOT_RNSt16remove_referenceIS3_E4typeE(%"class.std::shared_ptr"* dereferenceable(16) %8) #2
  call void @_ZNSt10shared_ptrI6lvalueEC2EOS1_(%"class.std::shared_ptr"* %7, %"class.std::shared_ptr"* dereferenceable(16) %9) #2
  br label %10

; <label>:10                                      ; preds = %6, %0
  %11 = phi %"class.std::shared_ptr"* [ %7, %6 ], [ null, %0 ]
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(16) %"class.std::shared_ptr"* @_ZNKSt13move_iteratorIPSt10shared_ptrI6lvalueEEdeEv(%"class.std::move_iterator"* %this) #4 align 2 {
  %1 = alloca %"class.std::move_iterator"*, align 8
  store %"class.std::move_iterator"* %this, %"class.std::move_iterator"** %1, align 8
  %2 = load %"class.std::move_iterator"** %1
  %3 = getelementptr inbounds %"class.std::move_iterator"* %2, i32 0, i32 0
  %4 = load %"class.std::shared_ptr"** %3, align 8
  %5 = call dereferenceable(16) %"class.std::shared_ptr"* @_ZSt4moveIRSt10shared_ptrI6lvalueEEONSt16remove_referenceIT_E4typeEOS5_(%"class.std::shared_ptr"* dereferenceable(16) %4) #2
  ret %"class.std::shared_ptr"* %5
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(8) %"class.std::move_iterator"* @_ZNSt13move_iteratorIPSt10shared_ptrI6lvalueEEppEv(%"class.std::move_iterator"* %this) #4 align 2 {
  %1 = alloca %"class.std::move_iterator"*, align 8
  store %"class.std::move_iterator"* %this, %"class.std::move_iterator"** %1, align 8
  %2 = load %"class.std::move_iterator"** %1
  %3 = getelementptr inbounds %"class.std::move_iterator"* %2, i32 0, i32 0
  %4 = load %"class.std::shared_ptr"** %3, align 8
  %5 = getelementptr inbounds %"class.std::shared_ptr"* %4, i32 1
  store %"class.std::shared_ptr"* %5, %"class.std::shared_ptr"** %3, align 8
  ret %"class.std::move_iterator"* %2
}

; Function Attrs: noreturn nounwind
declare void @llvm.trap() #9

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt10shared_ptrI6lvalueEC2EOS1_(%"class.std::shared_ptr"* %this, %"class.std::shared_ptr"* dereferenceable(16) %__r) unnamed_addr #4 align 2 {
  %1 = alloca %"class.std::shared_ptr"*, align 8
  %2 = alloca %"class.std::shared_ptr"*, align 8
  store %"class.std::shared_ptr"* %this, %"class.std::shared_ptr"** %1, align 8
  store %"class.std::shared_ptr"* %__r, %"class.std::shared_ptr"** %2, align 8
  %3 = load %"class.std::shared_ptr"** %1
  %4 = bitcast %"class.std::shared_ptr"* %3 to %"class.std::__shared_ptr"*
  %5 = load %"class.std::shared_ptr"** %2, align 8
  %6 = call dereferenceable(16) %"class.std::shared_ptr"* @_ZSt4moveIRSt10shared_ptrI6lvalueEEONSt16remove_referenceIT_E4typeEOS5_(%"class.std::shared_ptr"* dereferenceable(16) %5) #2
  %7 = bitcast %"class.std::shared_ptr"* %6 to %"class.std::__shared_ptr"*
  call void @_ZNSt12__shared_ptrI6lvalueLN9__gnu_cxx12_Lock_policyE2EEC2EOS3_(%"class.std::__shared_ptr"* %4, %"class.std::__shared_ptr"* dereferenceable(16) %7) #2
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt12__shared_ptrI6lvalueLN9__gnu_cxx12_Lock_policyE2EEC2EOS3_(%"class.std::__shared_ptr"* %this, %"class.std::__shared_ptr"* dereferenceable(16) %__r) unnamed_addr #4 align 2 {
  %1 = alloca %"class.std::__shared_ptr"*, align 8
  %2 = alloca %"class.std::__shared_ptr"*, align 8
  store %"class.std::__shared_ptr"* %this, %"class.std::__shared_ptr"** %1, align 8
  store %"class.std::__shared_ptr"* %__r, %"class.std::__shared_ptr"** %2, align 8
  %3 = load %"class.std::__shared_ptr"** %1
  %4 = getelementptr inbounds %"class.std::__shared_ptr"* %3, i32 0, i32 0
  %5 = load %"class.std::__shared_ptr"** %2, align 8
  %6 = getelementptr inbounds %"class.std::__shared_ptr"* %5, i32 0, i32 0
  %7 = load %class.lvalue** %6, align 8
  store %class.lvalue* %7, %class.lvalue** %4, align 8
  %8 = getelementptr inbounds %"class.std::__shared_ptr"* %3, i32 0, i32 1
  call void @_ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EEC2Ev(%"class.std::__shared_count"* %8) #2
  %9 = getelementptr inbounds %"class.std::__shared_ptr"* %3, i32 0, i32 1
  %10 = load %"class.std::__shared_ptr"** %2, align 8
  %11 = getelementptr inbounds %"class.std::__shared_ptr"* %10, i32 0, i32 1
  call void @_ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EE7_M_swapERS2_(%"class.std::__shared_count"* %9, %"class.std::__shared_count"* dereferenceable(8) %11) #2
  %12 = load %"class.std::__shared_ptr"** %2, align 8
  %13 = getelementptr inbounds %"class.std::__shared_ptr"* %12, i32 0, i32 0
  store %class.lvalue* null, %class.lvalue** %13, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EEC2Ev(%"class.std::__shared_count"* %this) unnamed_addr #4 align 2 {
  %1 = alloca %"class.std::__shared_count"*, align 8
  store %"class.std::__shared_count"* %this, %"class.std::__shared_count"** %1, align 8
  %2 = load %"class.std::__shared_count"** %1
  %3 = getelementptr inbounds %"class.std::__shared_count"* %2, i32 0, i32 0
  store %"class.std::_Sp_counted_base"* null, %"class.std::_Sp_counted_base"** %3, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EE7_M_swapERS2_(%"class.std::__shared_count"* %this, %"class.std::__shared_count"* dereferenceable(8) %__r) #4 align 2 {
  %1 = alloca %"class.std::__shared_count"*, align 8
  %2 = alloca %"class.std::__shared_count"*, align 8
  %__tmp = alloca %"class.std::_Sp_counted_base"*, align 8
  store %"class.std::__shared_count"* %this, %"class.std::__shared_count"** %1, align 8
  store %"class.std::__shared_count"* %__r, %"class.std::__shared_count"** %2, align 8
  %3 = load %"class.std::__shared_count"** %1
  %4 = load %"class.std::__shared_count"** %2, align 8
  %5 = getelementptr inbounds %"class.std::__shared_count"* %4, i32 0, i32 0
  %6 = load %"class.std::_Sp_counted_base"** %5, align 8
  store %"class.std::_Sp_counted_base"* %6, %"class.std::_Sp_counted_base"** %__tmp, align 8
  %7 = getelementptr inbounds %"class.std::__shared_count"* %3, i32 0, i32 0
  %8 = load %"class.std::_Sp_counted_base"** %7, align 8
  %9 = load %"class.std::__shared_count"** %2, align 8
  %10 = getelementptr inbounds %"class.std::__shared_count"* %9, i32 0, i32 0
  store %"class.std::_Sp_counted_base"* %8, %"class.std::_Sp_counted_base"** %10, align 8
  %11 = load %"class.std::_Sp_counted_base"** %__tmp, align 8
  %12 = getelementptr inbounds %"class.std::__shared_count"* %3, i32 0, i32 0
  store %"class.std::_Sp_counted_base"* %11, %"class.std::_Sp_counted_base"** %12, align 8
  ret void
}

; Function Attrs: inlinehint uwtable
define linkonce_odr zeroext i1 @_ZSteqIPSt10shared_ptrI6lvalueEEbRKSt13move_iteratorIT_ES8_(%"class.std::move_iterator"* dereferenceable(8) %__x, %"class.std::move_iterator"* dereferenceable(8) %__y) #6 {
  %1 = alloca %"class.std::move_iterator"*, align 8
  %2 = alloca %"class.std::move_iterator"*, align 8
  store %"class.std::move_iterator"* %__x, %"class.std::move_iterator"** %1, align 8
  store %"class.std::move_iterator"* %__y, %"class.std::move_iterator"** %2, align 8
  %3 = load %"class.std::move_iterator"** %1, align 8
  %4 = call %"class.std::shared_ptr"* @_ZNKSt13move_iteratorIPSt10shared_ptrI6lvalueEE4baseEv(%"class.std::move_iterator"* %3)
  %5 = load %"class.std::move_iterator"** %2, align 8
  %6 = call %"class.std::shared_ptr"* @_ZNKSt13move_iteratorIPSt10shared_ptrI6lvalueEE4baseEv(%"class.std::move_iterator"* %5)
  %7 = icmp eq %"class.std::shared_ptr"* %4, %6
  ret i1 %7
}

; Function Attrs: nounwind uwtable
define linkonce_odr %"class.std::shared_ptr"* @_ZNKSt13move_iteratorIPSt10shared_ptrI6lvalueEE4baseEv(%"class.std::move_iterator"* %this) #4 align 2 {
  %1 = alloca %"class.std::move_iterator"*, align 8
  store %"class.std::move_iterator"* %this, %"class.std::move_iterator"** %1, align 8
  %2 = load %"class.std::move_iterator"** %1
  %3 = getelementptr inbounds %"class.std::move_iterator"* %2, i32 0, i32 0
  %4 = load %"class.std::shared_ptr"** %3, align 8
  ret %"class.std::shared_ptr"* %4
}

; Function Attrs: uwtable
define linkonce_odr %"class.std::shared_ptr"* @_ZNSt16allocator_traitsISaISt10shared_ptrI6lvalueEEE8allocateERS3_m(%"class.std::allocator.6"* dereferenceable(1) %__a, i64 %__n) #3 align 2 {
  %1 = alloca %"class.std::allocator.6"*, align 8
  %2 = alloca i64, align 8
  store %"class.std::allocator.6"* %__a, %"class.std::allocator.6"** %1, align 8
  store i64 %__n, i64* %2, align 8
  %3 = load %"class.std::allocator.6"** %1, align 8
  %4 = bitcast %"class.std::allocator.6"* %3 to %"class.__gnu_cxx::new_allocator.7"*
  %5 = load i64* %2, align 8
  %6 = call %"class.std::shared_ptr"* @_ZN9__gnu_cxx13new_allocatorISt10shared_ptrI6lvalueEE8allocateEmPKv(%"class.__gnu_cxx::new_allocator.7"* %4, i64 %5, i8* null)
  ret %"class.std::shared_ptr"* %6
}

; Function Attrs: uwtable
define linkonce_odr %"class.std::shared_ptr"* @_ZN9__gnu_cxx13new_allocatorISt10shared_ptrI6lvalueEE8allocateEmPKv(%"class.__gnu_cxx::new_allocator.7"* %this, i64 %__n, i8*) #3 align 2 {
  %2 = alloca %"class.__gnu_cxx::new_allocator.7"*, align 8
  %3 = alloca i64, align 8
  %4 = alloca i8*, align 8
  store %"class.__gnu_cxx::new_allocator.7"* %this, %"class.__gnu_cxx::new_allocator.7"** %2, align 8
  store i64 %__n, i64* %3, align 8
  store i8* %0, i8** %4, align 8
  %5 = load %"class.__gnu_cxx::new_allocator.7"** %2
  %6 = load i64* %3, align 8
  %7 = call i64 @_ZNK9__gnu_cxx13new_allocatorISt10shared_ptrI6lvalueEE8max_sizeEv(%"class.__gnu_cxx::new_allocator.7"* %5) #2
  %8 = icmp ugt i64 %6, %7
  br i1 %8, label %9, label %10

; <label>:9                                       ; preds = %1
  call void @_ZSt17__throw_bad_allocv() #12
  unreachable

; <label>:10                                      ; preds = %1
  %11 = load i64* %3, align 8
  %12 = mul i64 %11, 16
  %13 = call noalias i8* @_Znwm(i64 %12)
  %14 = bitcast i8* %13 to %"class.std::shared_ptr"*
  ret %"class.std::shared_ptr"* %14
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNK9__gnu_cxx13new_allocatorISt10shared_ptrI6lvalueEE8max_sizeEv(%"class.__gnu_cxx::new_allocator.7"* %this) #4 align 2 {
  %1 = alloca %"class.__gnu_cxx::new_allocator.7"*, align 8
  store %"class.__gnu_cxx::new_allocator.7"* %this, %"class.__gnu_cxx::new_allocator.7"** %1, align 8
  %2 = load %"class.__gnu_cxx::new_allocator.7"** %1
  ret i64 1152921504606846975
}

; Function Attrs: noreturn
declare void @_ZSt17__throw_bad_allocv() #10

; Function Attrs: nobuiltin
declare noalias i8* @_Znwm(i64) #11

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNKSt6vectorISt10shared_ptrI6lvalueESaIS2_EE8max_sizeEv(%"class.std::vector"* %this) #4 align 2 {
  %1 = alloca %"class.std::vector"*, align 8
  store %"class.std::vector"* %this, %"class.std::vector"** %1, align 8
  %2 = load %"class.std::vector"** %1
  %3 = bitcast %"class.std::vector"* %2 to %"struct.std::_Vector_base"*
  %4 = call dereferenceable(1) %"class.std::allocator.6"* @_ZNKSt12_Vector_baseISt10shared_ptrI6lvalueESaIS2_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base"* %3) #2
  %5 = call i64 @_ZNSt16allocator_traitsISaISt10shared_ptrI6lvalueEEE8max_sizeERKS3_(%"class.std::allocator.6"* dereferenceable(1) %4) #2
  ret i64 %5
}

; Function Attrs: noreturn
declare void @_ZSt20__throw_length_errorPKc(i8*) #10

; Function Attrs: inlinehint nounwind uwtable
define linkonce_odr dereferenceable(8) i64* @_ZSt3maxImERKT_S2_S2_(i64* dereferenceable(8) %__a, i64* dereferenceable(8) %__b) #5 {
  %1 = alloca i64*, align 8
  %2 = alloca i64*, align 8
  %3 = alloca i64*, align 8
  store i64* %__a, i64** %2, align 8
  store i64* %__b, i64** %3, align 8
  %4 = load i64** %2, align 8
  %5 = load i64* %4, align 8
  %6 = load i64** %3, align 8
  %7 = load i64* %6, align 8
  %8 = icmp ult i64 %5, %7
  br i1 %8, label %9, label %11

; <label>:9                                       ; preds = %0
  %10 = load i64** %3, align 8
  store i64* %10, i64** %1
  br label %13

; <label>:11                                      ; preds = %0
  %12 = load i64** %2, align 8
  store i64* %12, i64** %1
  br label %13

; <label>:13                                      ; preds = %11, %9
  %14 = load i64** %1
  ret i64* %14
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt16allocator_traitsISaISt10shared_ptrI6lvalueEEE8max_sizeERKS3_(%"class.std::allocator.6"* dereferenceable(1) %__a) #4 align 2 {
  %1 = alloca %"class.std::allocator.6"*, align 8
  store %"class.std::allocator.6"* %__a, %"class.std::allocator.6"** %1, align 8
  %2 = load %"class.std::allocator.6"** %1, align 8
  %3 = invoke i64 @_ZNSt16allocator_traitsISaISt10shared_ptrI6lvalueEEE11_S_max_sizeIKS3_vEEmRT_i(%"class.std::allocator.6"* dereferenceable(1) %2, i32 0)
          to label %4 unwind label %5

; <label>:4                                       ; preds = %0
  ret i64 %3

; <label>:5                                       ; preds = %0
  %6 = landingpad { i8*, i32 } personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*)
          catch i8* null
  %7 = extractvalue { i8*, i32 } %6, 0
  call void @__clang_call_terminate(i8* %7) #9
  unreachable
}

; Function Attrs: nounwind uwtable
define linkonce_odr dereferenceable(1) %"class.std::allocator.6"* @_ZNKSt12_Vector_baseISt10shared_ptrI6lvalueESaIS2_EE19_M_get_Tp_allocatorEv(%"struct.std::_Vector_base"* %this) #4 align 2 {
  %1 = alloca %"struct.std::_Vector_base"*, align 8
  store %"struct.std::_Vector_base"* %this, %"struct.std::_Vector_base"** %1, align 8
  %2 = load %"struct.std::_Vector_base"** %1
  %3 = getelementptr inbounds %"struct.std::_Vector_base"* %2, i32 0, i32 0
  %4 = bitcast %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %3 to %"class.std::allocator.6"*
  ret %"class.std::allocator.6"* %4
}

; Function Attrs: nounwind uwtable
define linkonce_odr i64 @_ZNSt16allocator_traitsISaISt10shared_ptrI6lvalueEEE11_S_max_sizeIKS3_vEEmRT_i(%"class.std::allocator.6"* dereferenceable(1) %__a, i32) #4 align 2 {
  %2 = alloca %"class.std::allocator.6"*, align 8
  %3 = alloca i32, align 4
  store %"class.std::allocator.6"* %__a, %"class.std::allocator.6"** %2, align 8
  store i32 %0, i32* %3, align 4
  %4 = load %"class.std::allocator.6"** %2, align 8
  %5 = bitcast %"class.std::allocator.6"* %4 to %"class.__gnu_cxx::new_allocator.7"*
  %6 = call i64 @_ZNK9__gnu_cxx13new_allocatorISt10shared_ptrI6lvalueEE8max_sizeEv(%"class.__gnu_cxx::new_allocator.7"* %5) #2
  ret i64 %6
}

; Function Attrs: uwtable
define linkonce_odr void @_ZNSt16allocator_traitsISaISt10shared_ptrI6lvalueEEE12_S_constructIS2_JS2_EEENSt9enable_ifIXsr6__and_INS4_18__construct_helperIT_JDpT0_EE4typeEEE5valueEvE4typeERS3_PS8_DpOS9_(%"class.std::allocator.6"* dereferenceable(1) %__a, %"class.std::shared_ptr"* %__p, %"class.std::shared_ptr"* dereferenceable(16) %__args) #3 align 2 {
  %1 = alloca %"class.std::allocator.6"*, align 8
  %2 = alloca %"class.std::shared_ptr"*, align 8
  %3 = alloca %"class.std::shared_ptr"*, align 8
  store %"class.std::allocator.6"* %__a, %"class.std::allocator.6"** %1, align 8
  store %"class.std::shared_ptr"* %__p, %"class.std::shared_ptr"** %2, align 8
  store %"class.std::shared_ptr"* %__args, %"class.std::shared_ptr"** %3, align 8
  %4 = load %"class.std::allocator.6"** %1, align 8
  %5 = bitcast %"class.std::allocator.6"* %4 to %"class.__gnu_cxx::new_allocator.7"*
  %6 = load %"class.std::shared_ptr"** %2, align 8
  %7 = load %"class.std::shared_ptr"** %3, align 8
  %8 = call dereferenceable(16) %"class.std::shared_ptr"* @_ZSt7forwardISt10shared_ptrI6lvalueEEOT_RNSt16remove_referenceIS3_E4typeE(%"class.std::shared_ptr"* dereferenceable(16) %7) #2
  call void @_ZN9__gnu_cxx13new_allocatorISt10shared_ptrI6lvalueEE9constructIS3_JS3_EEEvPT_DpOT0_(%"class.__gnu_cxx::new_allocator.7"* %5, %"class.std::shared_ptr"* %6, %"class.std::shared_ptr"* dereferenceable(16) %8)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx13new_allocatorISt10shared_ptrI6lvalueEE9constructIS3_JS3_EEEvPT_DpOT0_(%"class.__gnu_cxx::new_allocator.7"* %this, %"class.std::shared_ptr"* %__p, %"class.std::shared_ptr"* dereferenceable(16) %__args) #4 align 2 {
  %1 = alloca %"class.__gnu_cxx::new_allocator.7"*, align 8
  %2 = alloca %"class.std::shared_ptr"*, align 8
  %3 = alloca %"class.std::shared_ptr"*, align 8
  store %"class.__gnu_cxx::new_allocator.7"* %this, %"class.__gnu_cxx::new_allocator.7"** %1, align 8
  store %"class.std::shared_ptr"* %__p, %"class.std::shared_ptr"** %2, align 8
  store %"class.std::shared_ptr"* %__args, %"class.std::shared_ptr"** %3, align 8
  %4 = load %"class.__gnu_cxx::new_allocator.7"** %1
  %5 = load %"class.std::shared_ptr"** %2, align 8
  %6 = bitcast %"class.std::shared_ptr"* %5 to i8*
  %7 = icmp eq i8* %6, null
  br i1 %7, label %12, label %8

; <label>:8                                       ; preds = %0
  %9 = bitcast i8* %6 to %"class.std::shared_ptr"*
  %10 = load %"class.std::shared_ptr"** %3, align 8
  %11 = call dereferenceable(16) %"class.std::shared_ptr"* @_ZSt7forwardISt10shared_ptrI6lvalueEEOT_RNSt16remove_referenceIS3_E4typeE(%"class.std::shared_ptr"* dereferenceable(16) %10) #2
  call void @_ZNSt10shared_ptrI6lvalueEC2EOS1_(%"class.std::shared_ptr"* %9, %"class.std::shared_ptr"* dereferenceable(16) %11) #2
  br label %12

; <label>:12                                      ; preds = %8, %0
  %13 = phi %"class.std::shared_ptr"* [ %9, %8 ], [ null, %0 ]
  ret void
}

; Function Attrs: uwtable
define linkonce_odr void @_ZNSt12_Vector_baseISt10shared_ptrI6lvalueESaIS2_EEC2Ev(%"struct.std::_Vector_base"* %this) unnamed_addr #3 align 2 {
  %1 = alloca %"struct.std::_Vector_base"*, align 8
  store %"struct.std::_Vector_base"* %this, %"struct.std::_Vector_base"** %1, align 8
  %2 = load %"struct.std::_Vector_base"** %1
  %3 = getelementptr inbounds %"struct.std::_Vector_base"* %2, i32 0, i32 0
  call void @_ZNSt12_Vector_baseISt10shared_ptrI6lvalueESaIS2_EE12_Vector_implC2Ev(%"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %3)
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt12_Vector_baseISt10shared_ptrI6lvalueESaIS2_EE12_Vector_implC2Ev(%"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %this) unnamed_addr #4 align 2 {
  %1 = alloca %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"*, align 8
  store %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %this, %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"** %1, align 8
  %2 = load %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"** %1
  %3 = bitcast %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %2 to %"class.std::allocator.6"*
  call void @_ZNSaISt10shared_ptrI6lvalueEEC2Ev(%"class.std::allocator.6"* %3) #2
  %4 = getelementptr inbounds %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %2, i32 0, i32 0
  store %"class.std::shared_ptr"* null, %"class.std::shared_ptr"** %4, align 8
  %5 = getelementptr inbounds %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %2, i32 0, i32 1
  store %"class.std::shared_ptr"* null, %"class.std::shared_ptr"** %5, align 8
  %6 = getelementptr inbounds %"struct.std::_Vector_base<std::shared_ptr<lvalue>, std::allocator<std::shared_ptr<lvalue> > >::_Vector_impl"* %2, i32 0, i32 2
  store %"class.std::shared_ptr"* null, %"class.std::shared_ptr"** %6, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSaISt10shared_ptrI6lvalueEEC2Ev(%"class.std::allocator.6"* %this) unnamed_addr #4 align 2 {
  %1 = alloca %"class.std::allocator.6"*, align 8
  store %"class.std::allocator.6"* %this, %"class.std::allocator.6"** %1, align 8
  %2 = load %"class.std::allocator.6"** %1
  %3 = bitcast %"class.std::allocator.6"* %2 to %"class.__gnu_cxx::new_allocator.7"*
  call void @_ZN9__gnu_cxx13new_allocatorISt10shared_ptrI6lvalueEEC2Ev(%"class.__gnu_cxx::new_allocator.7"* %3) #2
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZN9__gnu_cxx13new_allocatorISt10shared_ptrI6lvalueEEC2Ev(%"class.__gnu_cxx::new_allocator.7"* %this) unnamed_addr #4 align 2 {
  %1 = alloca %"class.__gnu_cxx::new_allocator.7"*, align 8
  store %"class.__gnu_cxx::new_allocator.7"* %this, %"class.__gnu_cxx::new_allocator.7"** %1, align 8
  %2 = load %"class.__gnu_cxx::new_allocator.7"** %1
  ret void
}

define internal void @_GLOBAL__sub_I_main.cpp() section ".text.startup" {
  call void @__cxx_global_var_init()
  ret void
}

attributes #0 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind }
attributes #3 = { uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #5 = { inlinehint nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #6 = { inlinehint uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #7 = { noinline noreturn nounwind }
attributes #8 = { nobuiltin nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #9 = { noreturn nounwind }
attributes #10 = { noreturn "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #11 = { nobuiltin "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #12 = { noreturn }

!llvm.ident = !{!0}

!0 = !{!"Ubuntu clang version 3.6.0-2ubuntu1~trusty1 (tags/RELEASE_360/final) (based on LLVM 3.6.0)"}
