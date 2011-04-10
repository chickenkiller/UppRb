#ifndef _Rb_Rb_h
#define _Rb_Rb_h

#include <Core/Core.h>
#include "ruby.h"

class RubyVm {
private:
	int last_state;
	int argc;
	char **argv;
	
public:
	RubyVm();
	virtual ~RubyVm();
	VALUE Eval(const Upp::String cmd);
};


#endif
