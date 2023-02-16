#pragma once

#include "RendererAPI.h"


namespace Jaguar
{

	class RendererAPIOpenGL : public RendererAPI
	{
	public:

		virtual void Init() override;
		virtual void Clear() override;
		virtual void SetClearColor(Vector4 color) override;
		virtual void DrawIndexed(int count) override;
	
	private:
	
	};
}
