#pragma once
#include "GameObject.h"


namespace GameObjectSpace {
	enum class CamType_t {
		perspective_t,
		ortho_t
	};
	class Camera : public GameObject
	{
	public:
		float projArgs[4] = { 0.0f };
		CamType_t myType = CamType_t::perspective_t;
		float lookAt[9] = { 0.0f };
		Camera();
		void update();
		virtual void SetCameraPosition();
		virtual void SetCameraLookAt();
		void SetCameraType(CamType_t t);
		void UpdateProjection();
		void SetProjArgs(float arg1, float arg2, float arg3, float arg4);
	};
}


