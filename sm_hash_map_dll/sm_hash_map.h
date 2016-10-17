//��ͬһ�����ж���˻�ͬʱʹ�ñ��⣬ ��ʹ�ñ���Ľ��̶����Թ���ԱȨ��ִ��
//Linux�����ɵ�32λ��̬���ӿ�ֻ����32λ������ʹ�ã���64λ���������в�������
#ifndef SM_HASH_MAP_H
#define SM_HASH_MAP_H

#ifdef __cplusplus

#ifdef _WIN32
#ifdef MYDLL
#define DLL_API extern "C" _declspec(dllexport) 
#else
#define DLL_API extern "C" _declspec(dllimport) 
#endif
#else
#define DLL_API extern "C"
#endif

#else
#define DLL_API
#endif

#include<cstddef>
typedef void* SM_HANDLE;

//����ͬһ��������ʹ��sm_server_init��sm_client_init
//name���ܺ������Ҳ��ܳ���128�ֽڣ�key_sizeΪ�����ڴ���key����󳤶ȣ�value_sizeΪ�����ڴ���value����󳤶ȣ�
//amountΪ��Ҫ�洢��key-value���� ����ֵΪNULLʱ��ʼ��ʧ�� factorΪ�������� һ��ʹ��Ĭ��ֵ0.75�� factor������ڴ�ռ������С�������ٶȱ�����
DLL_API SM_HANDLE sm_server_init(const char* name, unsigned int key_size, unsigned int value_size, unsigned int amount, double factor = 0.75);

//�ڱ�Ľ��̵���sm_server_init֮ǰ ���øú��� ������NULL, ��sm_server_init�İ汾��һ�·���NULL
//����ֵΪNULLʱ��ʼ��ʧ��
DLL_API SM_HANDLE sm_client_init(const char* name);

//�����µ�key value������е�key������value��
//����ֵ 0���ɹ��� -2001��ĳ������ΪNULL�� -2002��key��value�ĳ��ȷǷ� -2003�������ڴ�ռ������� -2009����ɾ��
DLL_API int sm_set_str(const SM_HANDLE, const char* key, const char* value);

DLL_API int sm_set_bytes(const SM_HANDLE, const char* key, const void* value, unsigned int value_len);

//����ʱlenΪvalue�Ļ�������С�� ���lenΪvalue����, ���len�����㹻��sm_get_str��valueĩβ���'\0'
//����ֵ 0���ɹ��� -1001��ĳ������ΪNULL�� -1002��key��value�ĳ��ȷǷ��� -1003��key�����ڣ� -1009����ɾ��
DLL_API int sm_get_str(const SM_HANDLE, const char *key, char* value, unsigned int& len);

DLL_API int sm_get_bytes(const SM_HANDLE handle, const char* key, void* value, unsigned int& len);

//����ֵ 0���ɹ��� -3001��ĳ������ΪNULL�� -3002��key������
DLL_API int sm_remove(const SM_HANDLE, const char* key);

//����ֵ 0���ɹ��� -4001��ĳ������ΪNULL�� -3009�Ա�ɾ��
//��������ɾ���ڴ�飬ֻ�Ǳ��Ϊɾ����
DLL_API int sm_delete(const SM_HANDLE handle);

//ɾ��handle��Ӧ���ڴ棬���ͷŶ�Ӧ�Ĺ����ڴ�
DLL_API int sm_release(const SM_HANDLE handle);

DLL_API unsigned int sm_size(const SM_HANDLE);

DLL_API unsigned int sm_memory_use(const SM_HANDLE);

DLL_API unsigned int sm_total_memory(const SM_HANDLE);
//Ͱƽ�����
DLL_API double sm_avg_depth(const SM_HANDLE);

DLL_API unsigned int sm_key_len(const SM_HANDLE handle);

DLL_API unsigned int sm_value_len(const SM_HANDLE handle);

DLL_API unsigned int sm_version();

//for sm_tool
DLL_API const char* sm_bucket_head(const SM_HANDLE handle);
#endif