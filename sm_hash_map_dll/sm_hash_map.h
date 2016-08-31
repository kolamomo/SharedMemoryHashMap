#pragma once
#ifdef MYDLL
#define DLL_API extern "C" _declspec(dllexport) 
#else
#define DLL_API extern "C" _declspec(dllimport) 
#endif

typedef void* SM_HANDLE;

//����ͬһ��������ʹ��sm_server_init��sm_client_init
//name���ܺ������Ҳ��ܳ���128�ֽڣ�key_sizeΪ�����ڴ���key����󳤶ȣ�value_sizeΪ�����ڴ���value����󳤶ȣ�
//amountΪ��Ҫ�洢��key-value���� ����ֵΪNULLʱ��ʼ��ʧ�� factorΪ�������� һ��ʹ��Ĭ��ֵ0.75�� factor������ڴ�ռ������С�������ٶȱ�����
DLL_API SM_HANDLE sm_server_init(const char* name, size_t key_size, size_t value_size, size_t amount, double factor = 0.75);

//�ڱ�Ľ��̵���sm_server_init֮ǰ ���øú��� ������NULL, ��sm_server_init�İ汾��һ�·���NULL
//����ֵΪNULLʱ��ʼ��ʧ��
DLL_API SM_HANDLE sm_client_init(const char* name);

//�����µ�key value������е�key������value��
//����ֵ 0���ɹ��� -2001��ĳ������ΪNULL�� -2002��key��value�ĳ��ȷǷ� -2003�������ڴ�ռ�����
DLL_API int sm_set(const SM_HANDLE, const char* key, const char* value);

//����ʱlenΪvalue�Ļ�������С�� ���lenΪstrlen(value)+1
//����ֵ 0���ɹ��� -1001��ĳ������ΪNULL�� -1002��key��value�ĳ��ȷǷ��� -1003��key������
DLL_API int sm_get(const SM_HANDLE, const char *key, char* value, size_t& len);

//����ֵ 0���ɹ��� -3001��ĳ������ΪNULL�� -3002��key������
DLL_API int sm_remove(const SM_HANDLE, const char* key);

//ɾ��handle��Ӧ���ڴ棬���ͷŶ�Ӧ�Ĺ����ڴ�
DLL_API void sm_release(const SM_HANDLE handle);

DLL_API size_t sm_size(const SM_HANDLE);

DLL_API size_t sm_memory_use(const SM_HANDLE);

DLL_API size_t sm_total_memory(const SM_HANDLE);
//Ͱƽ�����
DLL_API double sm_avg_depth(const SM_HANDLE);

DLL_API size_t sm_key_len(const SM_HANDLE handle);

DLL_API size_t sm_value_len(const SM_HANDLE handle);

DLL_API size_t sm_version();

//for sm_tools
DLL_API const char* sm_bucket_head(const SM_HANDLE handle);