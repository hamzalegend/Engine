#include "LayerStack.h"

Jaguar::LayerStack::LayerStack()
{
	m_layerInsert = m_Layers.begin();
}

Jaguar::LayerStack::~LayerStack()
{
	for (Layer* layer : m_Layers)
		delete layer;
}

void Jaguar::LayerStack::PushLayer(Layer* layer)
{
	m_layerInsert = m_Layers.emplace(m_layerInsert, layer);
}

void Jaguar::LayerStack::PushOverlay(Layer* overlay)
{
	m_Layers.emplace_back(overlay);
}

void Jaguar::LayerStack::PopLayer(Layer* layer)
{
	auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
	if (it != m_Layers.end())
	{
		m_Layers.erase(it);
		m_layerInsert--;
	}
}

void Jaguar::LayerStack::PopOverlay(Layer* overlay)
{
	auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
	if (it != m_Layers.end())
		m_Layers.erase(it);
}
