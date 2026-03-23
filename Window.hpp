#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

class Window {
public:
    Window(int width, int height, const std::string& title);
    ~Window(); // Distruttore: chiude tutto quando abbiamo finito

    bool shouldClose();   // Controlla se l'utente ha cliccato la X
    void update();        // Pulisce lo schermo e scambia i buffer
    GLFWwindow* getHandle(); // Serve per ImGui

private:
    GLFWwindow* m_window;
};

#endif

