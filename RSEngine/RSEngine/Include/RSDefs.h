#ifndef _RSDEFS_H_
#define _RSDEFS_H_

#include <string.h>
#include "Ogre\Ogre.h"
#include <vector>

namespace RSE{

	using namespace Ogre;

	//FWD Decelaration

	class RSOgreHandler;

	//--------------------
	
	//typedefs
	typedef std::vector<Ogre::SceneNode*> RSSceneNodesList;
	typedef Ogre::SceneManager RSSceneManager;
	typedef Ogre::Camera RSCamera;

	const String DefaultWindowTitle = "RS Engine";

	static const bool Release(void *ptr){
		bool result = false;
		if(ptr){
			delete ptr;
			ptr = NULL;
			result = true;
		}

		return result;
	}


	enum ORESULT{
		ORESULT_OK = 0,
		ORESULT_ERROR = 1,
	};

	struct FResult{
		ORESULT m_Result;
		String m_pcDescription;
	};

	static void SetError(FResult *errorObj, String errorString){
		errorObj->m_pcDescription = errorString;
		errorObj->m_Result = ORESULT_ERROR;
	}

}

#endif