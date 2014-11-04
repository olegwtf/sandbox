#include <stdio.h>
#include <dlfcn.h>

int main() {
	void *mylib_hdl;
	void (*make_thread)();
	
	mylib_hdl = dlopen("./libmy.so", RTLD_NOW|RTLD_GLOBAL);
	if (mylib_hdl == NULL) {
		printf("dlopen: %s\n", dlerror());
		return 1;
	}
	
	make_thread = (void (*)()) dlsym(mylib_hdl, "make_thread");
	if (make_thread == NULL) {
		printf("dlsym: %s\n", dlerror());
		return 1;
	}
	
	(*make_thread)();
	return 0;
}
