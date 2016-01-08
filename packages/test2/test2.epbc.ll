; ModuleID = 'test2.epbc'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%"class.std::ios_base::Init" = type { i8 }
%struct._funcReg = type { i8*, void (%"class.std::shared_ptr"*, %class.CodeGenContext*, %class.Node*)* }
%"class.std::shared_ptr" = type { %"class.std::__shared_ptr" }
%"class.std::__shared_ptr" = type { %class.lvalue*, %"class.std::__shared_count" }
%class.lvalue = type { i32 (...)** }
%"class.std::__shared_count" = type { %"class.std::_Sp_counted_base"* }
%"class.std::_Sp_counted_base" = type { i32 (...)**, i32, i32 }
%class.CodeGenContext = type <{ %class.IDTable*, %class.llcg*, %class.Node*, %"class.std::map", %"class.std::stack", i8, [7 x i8] }>
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

@_ZStL8__ioinit = internal global %"class.std::ios_base::Init" zeroinitializer, align 1
@.str = private unnamed_addr constant [25 x i8] c"test2_elite_plugin_init\0A\00", align 1
@.str1 = private unnamed_addr constant [19 x i8] c"Error for context\0A\00", align 1
@_ZL11macro_funcs = internal constant [2 x %struct._funcReg] [%struct._funcReg { i8* getelementptr inbounds ([6 x i8]* @.str2, i32 0, i32 0), void (%"class.std::shared_ptr"*, %class.CodeGenContext*, %class.Node*)* @_ZL11hello_macroP14CodeGenContextP4Node }, %struct._funcReg zeroinitializer], align 16
@.str2 = private unnamed_addr constant [6 x i8] c"hello\00", align 1
@.str3 = private unnamed_addr constant [14 x i8] c"Hello World!\0A\00", align 1
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
define void @test2_elite_plugin_init(%class.CodeGenContext* %context) #3 {
  %1 = alloca %class.CodeGenContext*, align 8
  store %class.CodeGenContext* %context, %class.CodeGenContext** %1, align 8
  %2 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([25 x i8]* @.str, i32 0, i32 0))
  %3 = load %class.CodeGenContext** %1, align 8
  %4 = icmp eq %class.CodeGenContext* %3, null
  br i1 %4, label %5, label %7

; <label>:5                                       ; preds = %0
  %6 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([19 x i8]* @.str1, i32 0, i32 0))
  br label %9

; <label>:7                                       ; preds = %0
  %8 = load %class.CodeGenContext** %1, align 8
  call void @_ZN14CodeGenContext18AddOrReplaceMacrosEPK8_funcReg(%class.CodeGenContext* %8, %struct._funcReg* getelementptr inbounds ([2 x %struct._funcReg]* @_ZL11macro_funcs, i32 0, i32 0))
  br label %9

; <label>:9                                       ; preds = %7, %5
  ret void
}

declare i32 @printf(i8*, ...) #0

declare void @_ZN14CodeGenContext18AddOrReplaceMacrosEPK8_funcReg(%class.CodeGenContext*, %struct._funcReg*) #0

; Function Attrs: uwtable
define internal void @_ZL11hello_macroP14CodeGenContextP4Node(%"class.std::shared_ptr"* noalias sret %agg.result, %class.CodeGenContext* %context, %class.Node* %node) #3 {
  %1 = alloca %class.CodeGenContext*, align 8
  %2 = alloca %class.Node*, align 8
  store %class.CodeGenContext* %context, %class.CodeGenContext** %1, align 8
  store %class.Node* %node, %class.Node** %2, align 8
  %3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([14 x i8]* @.str3, i32 0, i32 0))
  call void @_ZNSt10shared_ptrI6lvalueEC2EDn(%"class.std::shared_ptr"* %agg.result, i8* null) #2
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt10shared_ptrI6lvalueEC2EDn(%"class.std::shared_ptr"* %this, i8* %__p) unnamed_addr #4 align 2 {
  %1 = alloca %"class.std::shared_ptr"*, align 8
  %2 = alloca i8*, align 8
  store %"class.std::shared_ptr"* %this, %"class.std::shared_ptr"** %1, align 8
  store i8* %__p, i8** %2, align 8
  %3 = load %"class.std::shared_ptr"** %1
  %4 = bitcast %"class.std::shared_ptr"* %3 to %"class.std::__shared_ptr"*
  %5 = load i8** %2, align 8
  call void @_ZNSt12__shared_ptrI6lvalueLN9__gnu_cxx12_Lock_policyE2EEC2EDn(%"class.std::__shared_ptr"* %4, i8* %5) #2
  ret void
}

; Function Attrs: nounwind uwtable
define linkonce_odr void @_ZNSt12__shared_ptrI6lvalueLN9__gnu_cxx12_Lock_policyE2EEC2EDn(%"class.std::__shared_ptr"* %this, i8*) unnamed_addr #4 align 2 {
  %2 = alloca %"class.std::__shared_ptr"*, align 8
  %3 = alloca i8*, align 8
  store %"class.std::__shared_ptr"* %this, %"class.std::__shared_ptr"** %2, align 8
  store i8* %0, i8** %3, align 8
  %4 = load %"class.std::__shared_ptr"** %2
  %5 = getelementptr inbounds %"class.std::__shared_ptr"* %4, i32 0, i32 0
  store %class.lvalue* null, %class.lvalue** %5, align 8
  %6 = getelementptr inbounds %"class.std::__shared_ptr"* %4, i32 0, i32 1
  call void @_ZNSt14__shared_countILN9__gnu_cxx12_Lock_policyE2EEC2Ev(%"class.std::__shared_count"* %6) #2
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

define internal void @_GLOBAL__sub_I_main.cpp() section ".text.startup" {
  call void @__cxx_global_var_init()
  ret void
}

attributes #0 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind }
attributes #3 = { uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"Ubuntu clang version 3.6.0-2ubuntu1~trusty1 (tags/RELEASE_360/final) (based on LLVM 3.6.0)"}
