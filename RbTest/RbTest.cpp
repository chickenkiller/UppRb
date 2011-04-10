#include <Core/Core.h>
#include <Rb/Rb.h>

using namespace Upp;

CONSOLE_APP_MAIN
{
	RubyVm vm;
	//vm.Eval("p String.instance_methods");
	vm.Eval("p $:");
	vm.Eval("def toto; puts 5/0; end; toto");
	vm.Eval("require 'yaml'; puts [1,2,3,'hello'].to_yaml");
	VALUE v = vm.Eval("'a ruby string'");
	Cout() << RSTRING_PTR(v) << "\n";
}

