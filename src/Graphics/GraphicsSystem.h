#include "ApostatePCH.h"

#include "Singleton/Singleton.h"

#include "webgpu.h"

struct GLFWwindow;


namespace apostate
{
    struct GraphicsSystem : SingletonBase<GraphicsSystem>
    {
        GraphicsSystem();
        ~GraphicsSystem();


        GLFWwindow* m_glfwWindow{};
        WGPUInstance m_wgpuInstance{};
        WGPUAdapter m_wgpuAdapter{};
        WGPUDevice m_wgpuDevice{};
        WGPUQueue m_wgpuQueue{};
    };
}