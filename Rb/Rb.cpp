#include "Rb.h"

using namespace Upp;

RubyVm::RubyVm()
{
	argc = CommandLine().GetCount() + 1;
	argv = new char* [argc];
	argv[0] = strdup(GetExeTitle());
	for(int i=1; i<argc; i++)
		argv[i] = strdup(CommandLine()[i-1]);
	ruby_sysinit(&argc, &argv);
	{
		RUBY_INIT_STACK;
		ruby_init();
		ruby_init_loadpath();
	}
}

RubyVm::~RubyVm()
{
	for(int i=0; i<argc; i++)
		free(argv[i]);
	delete [] argv;
}

VALUE RubyVm::Eval(const String cmd)
{
	VALUE ret = rb_eval_string_protect(cmd, &last_state);
	if(last_state)
	{
		VALUE exc = rb_gv_get("$!");
		Cerr() << rb_obj_classname(exc) << ": " <<
			RSTRING_PTR(rb_obj_as_string(exc)) << "\n";
	}
	return ret;
}

