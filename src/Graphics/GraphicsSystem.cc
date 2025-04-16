#include "ApostatePCH.h"
#include "GraphicsSystem.h"

#include "Platform/CommandLineOptions/CommandLineOptions.h"

#include "GLFW/glfw3.h"

namespace apostate
{
    GraphicsSystem::GraphicsSystem()
    {
        if (g_cmdlineHeadless)
            return;

        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        m_glfwWindow = glfwCreateWindow(640, 480, "ari", nullptr, nullptr);
        if (!m_glfwWindow)
            exit(-1);
        
        m_wgpuInstance = wgpuCreateInstance(nullptr);
        if (!m_wgpuInstance)
            exit(-2);

            
        
    }

    GraphicsSystem::~GraphicsSystem()
    {

        if (m_wgpuInstance)
            wgpuInstanceRelease(m_wgpuInstance);
        if (m_glfwWindow)
            glfwDestroyWindow(m_glfwWindow);
        glfwTerminate();
    }
};