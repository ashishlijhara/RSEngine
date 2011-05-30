#ifndef _RSUNCOPYABLE_H_
#define _RSUNCOPYABLE_H_

namespace RSE{
	/*
	*	Class to disallow implicit object copying.
	*/
	class Uncopyable{
	private:
		Uncopyable& operator=(const Uncopyable& rhs);
		Uncopyable(const Uncopyable& rhs);
	public:
		Uncopyable(){}
		virtual ~Uncopyable(){}
	};
}

#endif