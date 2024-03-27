#pragma once

#include "common.h"
// 헤더 파일(C++)
// https://learn.microsoft.com/ko-kr/cpp/cpp/header-files-cpp?view=msvc-170
// 정의부 중복 컴파일을 방지하여 컴파일 속도가 개선, 선언과 구현부의 분할로 가독성 증가 및 관리의 편의
// *C/C++에서 선언은 중복되어도 괜찮지만 정의는 중복되어선 안됨.
// *include는 해당파일을 그대로 붙여넣기 때문에 한파일에 선언과 정의가 같이하면 include 할때마다 같은 이름의 심볼(함수명, 변수명)이 중복 정의

extern int g_extern_num;

void funTest();
void print_g_static_num();