#pragma once
#include "GameObjectLib.h"
#include "GameObject.h"

namespace GameObjectSpace {

	class Canvas: public GameObject
	{
	public:
		float width = 0.0f, height = 0.0f;
		bool fullScreen = false;
		float scale_x=1.0f, scale_y = 1.0f;
		bool isUI = false;
		vector<float*> meshScales;
		vector<float*> meshWidthHeight;
		vector<float*> meshPositions;
		vector<GLint*> meshTextures;
		VSShaderLib * shader;
		Canvas():GameObject() {
			;
		}
		Canvas(VSShaderLib *shaderUI) :Canvas() {
		SetUIShader(shaderUI);
		}
		void SetUIGlobalPosition(float x, float y);
		void SetUILocalPosition(float x, float y);
		void initDraw(GLuint shader) override;
		void generateMesh(int i);
		void update();
		void SetScale(float x, float y);
		void DrawUI() override;
		void SetUI(bool u) override { isUI = u; }
		bool GetUI() override { return isUI;  }
		void SetUIShader(VSShaderLib* s) { shader = s; shaderIndex = s->getProgramIndex(); }
		bool GetFullScreen() override { return true; }
		void SetFullScreen(bool f) { fullScreen = f; }
		void SetWidth(float w) override {  width = w;  }
		void SetHeight(float h) override{ height = h; }
		//private:
		//void start() override;
	};
}