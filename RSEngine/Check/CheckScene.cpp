#include "CheckScene.h"

namespace Check{

	FResult CheckScene::VInitScene(){
		FResult returnResult;
		memset(&returnResult, 0, sizeof(FResult));


		m_pRSRoot = RSOgreHandler::getSingletonPtr()->GetRSRoot();
		m_pRSSceneManager = static_cast<RSSceneManager*>(m_pRSRoot->createSceneManager(Ogre::ST_GENERIC, "Check Scene Manager"));


//----------------------------------------------------------------------------------------------------------------
		m_pRSCamera = m_pRSSceneManager->createCamera("CheckCammera");
		m_pRSCamera->setAspectRatio(Real(RSOgreHandler::getSingletonPtr()->GetViewport()->getActualWidth())/Real(RSOgreHandler::getSingletonPtr()->GetViewport()->getActualHeight()));
		
		m_pRSCamera->setPosition(Ogre::Vector3(0,0,20));
    // Look back along -Z
		m_pRSCamera->lookAt(Ogre::Vector3(0,0,-300));
		m_pRSCamera->setNearClipDistance(5);

		RSOgreHandler::getSingletonPtr()->GetViewport()->setCamera(m_pRSCamera);
		

		Entity* ogreHead = m_pRSSceneManager->createEntity("Head", "sinbad.mesh");
 
		SceneNode* headNode = m_pRSSceneManager->getRootSceneNode()->createChildSceneNode();
		headNode->attachObject(ogreHead);
 
    // Set ambient light
		m_pRSSceneManager->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));
 
    // Create a light
		Light* l = m_pRSSceneManager->createLight("MainLight");
		l->setPosition(20,80,50);
//------------------------------------------------------------------------------------------------------------------------


		return returnResult;
	}

	FResult CheckScene::VUpdateScene(const float &delTime){
		FResult returnResult;
		memset(&returnResult, 0, sizeof(FResult));



		return returnResult;
	}

	FResult CheckScene::VPauseScene(const bool &paused){
		FResult returnResult;
		memset(&returnResult, 0, sizeof(FResult));
		
		m_bPaused = paused;


		return returnResult;
	}

	FResult CheckScene::VRender(){
		FResult returnResult;
		memset(&returnResult, 0, sizeof(FResult));
		


		return returnResult;
	}

	FResult CheckScene::VEndScene(){
		FResult returnResult;
		memset(&returnResult, 0, sizeof(FResult));

		return returnResult;
	}

	FResult CheckScene::VCleanupScene(){
		FResult returnResult;
		memset(&returnResult, 0, sizeof(FResult));

		assert(m_pRSSceneManager);

		m_pRSSceneManager->clearScene();
		m_pRSSceneManager->destroyCamera(m_pRSCamera);
		m_pRSRoot->destroySceneManager(m_pRSSceneManager);

		return returnResult;
	}

}