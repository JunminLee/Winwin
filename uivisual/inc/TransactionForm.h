//
// Tizen C++ SDK
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.1 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef _TRANSACTION_FORM_H_
#define _TRANSACTION_FORM_H_

#include "AnimationBaseForm.h"

class TransactionForm
	: public AnimationBaseForm
{
public:
	TransactionForm(void);
	virtual ~TransactionForm(void);

	virtual result OnInitializing(void);

	virtual void Play(void);
	virtual void Stop(void);

private:
	Tizen::Ui::Animations::VisualElement* __pRect1;
	Tizen::Ui::Animations::VisualElement* __pRect2;
	Tizen::Ui::Animations::VisualElement* __pRect3;
	Tizen::Ui::Animations::VisualElement* __pRect4;
	Tizen::Ui::Animations::VisualElement* __pRect5;
	Tizen::Ui::Animations::VisualElement* __pRect6;

	Tizen::Ui::Controls::Label* __pLabel;

	Tizen::Ui::Animations::IAnimationTransactionEventListener*	__pListener1;
	Tizen::Ui::Animations::IAnimationTransactionEventListener*	__pListener2;
	Tizen::Ui::Animations::IAnimationTransactionEventListener*	__pListener3;

	int __transactionId;

	static const float __buttonSize = 150.0f;
};

class MyEventListener1
	: public Tizen::Ui::Animations::IAnimationTransactionEventListener
{
public:
	MyEventListener1(Tizen::Ui::Controls::Label* pLabel)
		: __pLabel(pLabel)
	{
	}
	virtual ~MyEventListener1(void){}

	virtual void OnAnimationTransactionStarted(int transactionId){}
	virtual void OnAnimationTransactionStopped(int transactionId){}
	virtual void OnAnimationTransactionFinished(int transactionId);

	Tizen::Ui::Controls::Label* __pLabel;
 };

class MyEventListener2
	: public Tizen::Ui::Animations::IAnimationTransactionEventListener
{
public:
	MyEventListener2(Tizen::Ui::Controls::Label* pLabel)
		: __pLabel(pLabel)
	{
	}
	virtual ~MyEventListener2(void){}

	virtual void OnAnimationTransactionStarted(int transactionId){}
	virtual void OnAnimationTransactionStopped(int transactionId){}
	virtual void OnAnimationTransactionFinished(int transactionId);

	Tizen::Ui::Controls::Label* __pLabel;
 };

class MyEventListener3
	: public Tizen::Ui::Animations::IAnimationTransactionEventListener
{
public:
	MyEventListener3(Tizen::Ui::Controls::Label* pLabel)
		: __pLabel(pLabel)
	{
	}
	virtual ~MyEventListener3(void){}

	virtual void OnAnimationTransactionStarted(int transactionId){}
	virtual void OnAnimationTransactionStopped(int transactionId){}
	virtual void OnAnimationTransactionFinished(int transactionId);

	Tizen::Ui::Controls::Label* __pLabel;
};
#endif // _TRANSACTION_FORM_H_
