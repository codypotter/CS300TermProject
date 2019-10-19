#ifndef UTILS_H
#define UTILS_H

#define Record Json::Value
#define internal static
#define global static
#define local static
#define external extern

#include <stdint.h>
#include <float.h>

#define i8 int8_t
#define u8 uint8_t
#define i16 int16_t
#define u16 uint16_t
#define i32 int32_t
#define u32 uint32_t
#define i64 int64_t
#define u64 uint64_t
#define f32 float
#define f64 double

#include <fstream>

internal inline
Record read_json(const char* path) {
    std::ifstream ifs(path);
    Json::Reader reader;
    Json::Value obj;
    reader.parse(ifs, obj);
    return obj;
}

internal inline
char* duplicate_string(const char* s) {
    char* d = (char*)malloc(strlen(s) + 1);
    if(d == NULL) return NULL;
    strcpy(d, s);
    return d;
}

#endif
