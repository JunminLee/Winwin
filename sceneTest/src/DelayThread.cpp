#include "DelayThread.h"

using namespace Tizen::Base::Runtime;
using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

DelayThread::DelayThread() {
	// TODO Auto-generated constructor stub

}

DelayThread::~DelayThread() {
	// TODO Auto-generated destructor stub
}
result DelayThread::Construct(void) {
	return Thread::Construct();
}

Object* DelayThread::run() {

	Tizen::Base::Runtime::Thread::Sleep(3000);

	return null;
}
