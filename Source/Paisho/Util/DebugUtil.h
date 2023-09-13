#pragma once

DECLARE_LOG_CATEGORY_EXTERN(PaishoGeneral, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(PaishoVerbose, Log, All);

#define VERBOSE(f_, ...) UE_LOG(PaishoVerbose, Log, TEXT(f_), ##__VA_ARGS__)
#define LOG(f_, ...) UE_LOG(PaishoGeneral, Log, TEXT(f_), ##__VA_ARGS__)
#define WARNING(f_, ...) UE_LOG(PaishoGeneral, Warning, TEXT(f_), ##__VA_ARGS__)
#define ERROR(f_, ...) UE_LOG(PaishoGeneral, Error, TEXT(f_), ##__VA_ARGS__)
