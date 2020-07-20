#ifndef _SINGLETON_H
#define _SINGLETON_H

template <typename _T>
class Singleton {

protected:
	Singleton() {}
	virtual ~Singleton() {}
	Singleton(const Singleton& r) {}
	Singleton& operator=(const Singleton& r) {}

public:
	static _T* Instance() {
		static _T inst;
		return &inst;
	};

};

#endif 
