#ifndef DELAYTHREAD_H_
#define DELAYTHREAD_H_
#include <FBase.h>
using namespace Tizen::Base;
using namespace Tizen::Base::Runtime;


class DelayThread : public Tizen::Base::Object
            ,public Tizen::Base::Runtime::Thread
{
public:
	DelayThread();
	virtual ~DelayThread();
	 Object* run();
	 result Construct(void);

};

#endif /* DELAYTHREAD_H_ */
