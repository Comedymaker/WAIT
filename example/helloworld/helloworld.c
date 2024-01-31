#include "benchmark.h"


void __attribute__((noinline)) rtcbenchmark_measure_native_performance() {
    rtc_startBenchmarkMeasurement_Native();
    int a = 1, b = 2;
    a += b;
    printStr("Genshin impart from WAIT! Num:");
    printInt(a);
    rtc_stopBenchmarkMeasurement();
}
void javax_rtcbench_RTCBenchmark_void_test_native() {
    rtcbenchmark_measure_native_performance();
}