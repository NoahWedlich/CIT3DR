#include "Core.h"
#include "Log.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include <stdio.h>
#include <iostream>

int main()
{
	CITR::Log::Init();

	CITR::WindowResizeEvent e(1280, 720);

	if (e.IsInCategory(CITR::EventCategoryApplication))
	{
		LOG_DEBUG(e.ToString());
	}

}