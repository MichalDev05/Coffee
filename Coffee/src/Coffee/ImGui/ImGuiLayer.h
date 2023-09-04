#pragma once

#include "Coffee/Layer.h"

namespace Coffee {
	class COFFEE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();

		void OnUpdate();
		void OnEvent(Event& event);


	private:
		float m_Time;

	};
}


