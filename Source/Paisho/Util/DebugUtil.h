#pragma once

DECLARE_LOG_CATEGORY_EXTERN(PaishoGeneral, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(PaishoVerbose, Log, All);

#define VERBOSE(f_, ...) UE_LOG(PaishoVerbose, Log, TEXT(f_), ##__VA_ARGS__)
#define LOG(f_, ...) UE_LOG(PaishoGeneral, Log, TEXT(f_), ##__VA_ARGS__)
#define WARNING(f_, ...) UE_LOG(PaishoGeneral, Warning, TEXT(f_), ##__VA_ARGS__)
#define ERROR(f_, ...) UE_LOG(PaishoGeneral, Error, TEXT(f_), ##__VA_ARGS__)
#define PRINT(f_, ...) UE_LOG(PaishoGeneral, Error, TEXT(f_), ##__VA_ARGS__)

/* spits out an error message if the if check failed, doesn't halt execution but hopefully leaves some bread crumbs for debugging */
#define ELSE_ERROR(message) else \
{ \
	ERROR(message); \
}
