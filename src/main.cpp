#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>

#include <imgui-SFML.h>
#include <imgui.h>

int main(int argc, char *argv[])
{
    std::cout << "Hello World" << std::endl;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Tutorial", sf::Style::Close, settings);
    settings = window.getSettings();
    std::cout << SFML_VERSION_MAJOR << "." << SFML_VERSION_MINOR << "." << SFML_VERSION_PATCH << std::endl;
    std::cout << settings.majorVersion << "." << settings.minorVersion << std::endl;

    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    sf::Clock deltaClock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }
        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::ShowDemoWindow();

        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }
    ImGui::SFML::Shutdown();

    return 0;
}