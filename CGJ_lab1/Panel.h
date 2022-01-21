#pragma once
#include "ComponentLib.h"

namespace GameObjectSpace
{
	class UserInterface;
	class Panel :public Component
	{

	public:
		float simpleColor[4] = { 1.0f };
		float position[3] = { 0.0f };
		float scale[2] = { 1.0f, 1.0f };
		float width = 0.0f, height = 0.0f;
		int mesh_index = 0;
		GLint textureId = -1;
		Panel(GameObject* owner) :Component(owner) {
			;
		}
		Panel(GameObject* owner, float x, float y, float scale_x, float scale_y, float r, float g, float b, float alpha) :Panel(owner) {
			setPosition(x, y);
			setScale(scale_x, scale_y);
			setSimpleColor(r, g, b, alpha);
		}

		void update() override;
		void updatePositions();
		void updateScales();
		void updateWidthHeight();
		void updateColors();
		void init() override;
		void initMaterial(Material * m, float r, float g, float b, float a);
		int getIndex(vector<float*> v, float* K);
		const char* GetType() override { return "Canvas"; }
		void setSimpleColor(float r, float g, float b, float a) { simpleColor[0] = r, simpleColor[1] = g, simpleColor[2] = b;  simpleColor[3] = a; }
		void setPosition(float x, float y) { position[0] = x, position[1] = y; }
		void setScale(float x, float y) { scale[0] = x, scale[1] = y; }
		void setWidth(float w) { width = w; }
		void setHeight(float h) { height = h; }
		void setTextureId(int id) { textureId = id; }


	};
}