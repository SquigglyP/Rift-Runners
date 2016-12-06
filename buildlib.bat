cls
cl /c /EHsc /Fo.\obj\ /I.\source\headers source\filename.cpp
lib obj\filename.obj /OUT:bin\filename.lib
copy bin\filename.lib G:\libs\libname\filename.lib
copy source\headers\filename.h G:\libs\include\libname\filename.h