(module
  (type (;0;) (func))
  (type (;1;) (func (param i32) (result i32)))
  (type (;2;) (func (param i32)))
  (import "env" "rtc_startBenchmarkMeasurement_Native" (func (;0;) (type 0)))
  (import "env" "printStr" (func (;1;) (type 1)))
  (import "env" "printInt" (func (;2;) (type 2)))
  (import "env" "rtc_stopBenchmarkMeasurement" (func (;3;) (type 0)))
  (func (;4;) (type 0))
  (func (;5;) (type 0)
    call 0
    i32.const 1024
    call 1
    drop
    i32.const 3
    call 2
    call 3)
  (func (;6;) (type 0)
    call 5)
  (table (;0;) 1 1 funcref)
  (memory (;0;) 1)
  (global (;0;) (mut i32) (i32.const 1072))
  (global (;1;) i32 (i32.const 1024))
  (global (;2;) i32 (i32.const 1055))
  (global (;3;) i32 (i32.const 1024))
  (global (;4;) i32 (i32.const 1072))
  (global (;5;) i32 (i32.const 0))
  (global (;6;) i32 (i32.const 1))
  (export "memory" (memory 0))
  (export "__wasm_call_ctors" (func 4))
  (export "rtcbenchmark_measure_native_performance" (func 5))
  (export "javax_rtcbench_RTCBenchmark_void_test_native" (func 6))
  (export "__dso_handle" (global 1))
  (export "__data_end" (global 2))
  (export "__global_base" (global 3))
  (export "__heap_base" (global 4))
  (export "__memory_base" (global 5))
  (export "__table_base" (global 6))
  (data (;0;) (i32.const 1024) "Genshin impart from WAIT! Num:\00"))