#include <SFML/Graphics.hpp>

// Clase para la ventana principal de la aplicación
class MainWindow
{
public:
    MainWindow() : window(sf::VideoMode(800, 600), "Mi aplicación SFML")
    {
        window.setFramerateLimit(60);
        window.setVerticalSyncEnabled(true);
    }

    // Bucle principal de la aplicación
    void run()
    {
        while (window.isOpen())
        {
            processEvents();
            update();
            render();
        }
    }

private:
    // Procesar los eventos de la ventana
    void processEvents()
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                case sf::Keyboard::Key::Escape:
                    window.close();
                    break;
                default:
                    break;
                }
            default:
                break;
            }
        }
    }

    // Actualizar la lógica de la aplicación
    void update()
    {
        // Actualizar el estado de la aplicación aquí
        // ...
    }

    // Dibujar en la ventana
    void render()
    {
        window.clear(sf::Color::Black);
        
        // Dibujar cualquier cosa aquí
        sf::RectangleShape rec({100, 100});
        rec.setOrigin(50, 50);
        rec.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);
        window.draw(rec);

        // Actualizar la ventana
        window.display();
    }

    sf::RenderWindow window;
};

int main()
{
    MainWindow mainWindow;

    mainWindow.run();

    return 0;
}
