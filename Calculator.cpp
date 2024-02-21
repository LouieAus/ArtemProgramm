#include <iostream>
#include <SFML/Graphics.hpp>

// Функция создания кнопки
sf::RectangleShape createButton(int x, int y, int w, int h) {
    sf::RectangleShape button(sf::Vector2f(w, h));
    button.setPosition(x, y);
    return button;
}

// Функция, проверяющая нахождение курсора в кнопке
bool mouseInButton(sf::RectangleShape mib, sf::RenderWindow& window)
{
    int x_r = mib.getPosition().x;
    int y_r = mib.getPosition().y;

    int w = mib.getSize().x;
    int h = mib.getSize().y;

    int m = sf::Mouse::getPosition(window).x;
    int s = sf::Mouse::getPosition(window).y;

    if ((x_r <= m && m <= x_r + w) && (y_r <= s && s <= y_r + h))
    {
        return true;
    }
    else
        return false;
}

int main()
{
    bool clicked = false;
    bool clickedEq = false;

    long double number = 0;
    long double numberA = 0;

    enum class operations { ADD, SUBTRACT, MULTIPLY, DIVIDE };
    operations OP;

    sf::Font font;
    font.loadFromFile("mine_font.otf");

    sf::RenderWindow window(sf::VideoMode(600, 800), "Kolkulator", sf::Style::Titlebar | sf::Style::Close);
    
    sf::Color buttonColor1(255, 179, 0);    // Цвет кнопок
    sf::Color buttonColor2(255, 214, 117);  // Цвет кнопок при наведении
    sf::Color buttonColor3(179, 125, 0);    // Цвет кнопок при нажатии

    // =================== КНОПКИ ===================
    
    // --------- Кнопки 0 - 9 ---------
    // Создаем кнопки
    sf::RectangleShape button0 = createButton(200, 800-100, 200, 100);
    sf::RectangleShape button1 = createButton(0, 800 - 200, 200, 100);
    sf::RectangleShape button2 = createButton(200, 800 - 200, 200, 100);
    sf::RectangleShape button3 = createButton(400, 800 - 200, 200, 100);
    sf::RectangleShape button4 = createButton(0, 800 - 300, 200, 100);
    sf::RectangleShape button5 = createButton(200, 800 - 300, 200, 100);
    sf::RectangleShape button6 = createButton(400,800 - 300, 200, 100);
    sf::RectangleShape button7 = createButton(0, 800 - 400, 200, 100);
    sf::RectangleShape button8 = createButton(200, 800 - 400, 200, 100);
    sf::RectangleShape button9 = createButton(400, 800 - 400, 200, 100);

    std::vector< sf::RectangleShape> buttons;
    buttons.push_back(button0);
    buttons.push_back(button1);
    buttons.push_back(button2);
    buttons.push_back(button3);
    buttons.push_back(button4);
    buttons.push_back(button5);
    buttons.push_back(button6);
    buttons.push_back(button7);
    buttons.push_back(button8);
    buttons.push_back(button9);

    // Меняем цвет кнопок
    for (int i = 0; i < buttons.size(); i++) {
        buttons[i].setFillColor(buttonColor1);
    }
    
    // --------- Текст кнопок 0 - 9 ---------
    // Создаем текст для кнопок
    sf::Text nm_text;
    nm_text.setFont(font);
    nm_text.setString(std::to_string(number));
    nm_text.setPosition(30, 30);
    nm_text.setCharacterSize(40);

    sf::Text b0_text;
    b0_text.setFont(font);
    b0_text.setString("0");
    b0_text.setCharacterSize(40);

    sf::Text b1_text;
    b1_text.setFont(font);
    b1_text.setString("1");

    sf::Text b2_text;
    b2_text.setFont(font);
    b2_text.setString("2");

    sf::Text b3_text;
    b3_text.setFont(font);
    b3_text.setString("3");

    sf::Text b4_text;
    b4_text.setFont(font);
    b4_text.setString("4");

    sf::Text b5_text;
    b5_text.setFont(font);
    b5_text.setString("5");

    sf::Text b6_text;
    b6_text.setFont(font);
    b6_text.setString("6");

    sf::Text b7_text;
    b7_text.setFont(font);
    b7_text.setString("7");

    sf::Text b8_text;
    b8_text.setFont(font);
    b8_text.setString("8");

    sf::Text b9_text;
    b9_text.setFont(font);
    b9_text.setString("9");

    // меняем цвет текста для кнопок
    b0_text.setFillColor(sf::Color::Black);
    b1_text.setFillColor(sf::Color::Black);
    b2_text.setFillColor(sf::Color::Black);
    b3_text.setFillColor(sf::Color::Black);
    b4_text.setFillColor(sf::Color::Black);
    b5_text.setFillColor(sf::Color::Black);
    b6_text.setFillColor(sf::Color::Black);
    b7_text.setFillColor(sf::Color::Black);
    b8_text.setFillColor(sf::Color::Black);
    b9_text.setFillColor(sf::Color::Black);

    // Устанавливаем позицию текста для кнопок
    b0_text.setPosition(285, 720);
    b1_text.setPosition(85, 620);
    b2_text.setPosition(285, 620);
    b3_text.setPosition(485, 620);
    b4_text.setPosition(85, 520);
    b5_text.setPosition(285, 520);
    b6_text.setPosition(485, 520);
    b7_text.setPosition(85, 420);
    b8_text.setPosition(285, 420);
    b9_text.setPosition(485, 420);

    // --------- Остальные кнопки ---------
    // Создаем кнопки
    
    // Кнопка стереть
    sf::RectangleShape buttonCl = createButton(400, 800 - 500, 200, 100);
    buttons.push_back(buttonCl);

    // Кнопка "+"
    sf::RectangleShape buttonPl = createButton(0, 800 - 600, 200, 100);
    buttons.push_back(buttonPl);

    // Кнопка "-"
    sf::RectangleShape buttonMi = createButton(0, 800 - 500, 200, 100);
    buttons.push_back(buttonMi);
    
    // Кнопка "*"
    sf::RectangleShape buttonMu = createButton(200, 800 - 600, 200, 100);
    buttons.push_back(buttonMu);

    // Кнопка "/"
    sf::RectangleShape buttonDi = createButton(200, 800 - 500, 200, 100);
    buttons.push_back(buttonDi);

    // Кнопка "="
    sf::RectangleShape buttonEq = createButton(400, 800 - 600, 200, 100);
    buttons.push_back(buttonEq);

    // Создаем текст для кнопок
    sf::Text cl_text;
    cl_text.setFont(font);
    cl_text.setString("<-");

    sf::Text Pl_text;
    Pl_text.setFont(font);
    Pl_text.setString("+");

    sf::Text Mi_text;
    Mi_text.setFont(font);
    Mi_text.setString("-");

    sf::Text Mu_text;
    Mu_text.setFont(font);
    Mu_text.setString("*");

    sf::Text Di_text;
    Di_text.setFont(font);
    Di_text.setString("/");

    sf::Text Eq_text;
    Eq_text.setFont(font);
    Eq_text.setString("=");

    // Устанавливаем цвет для текста
    cl_text.setFillColor(sf::Color::Black);
    Pl_text.setFillColor(sf::Color::Black);
    Mi_text.setFillColor(sf::Color::Black);
    Mu_text.setFillColor(sf::Color::Black);
    Di_text.setFillColor(sf::Color::Black);
    Eq_text.setFillColor(sf::Color::Black);

    // Устанавливаем позицию для текста
    cl_text.setPosition(sf::Vector2f(480, 320));
    Pl_text.setPosition(sf::Vector2f(85, 220));
    Mi_text.setPosition(sf::Vector2f(85, 320));
    Mu_text.setPosition(sf::Vector2f(285, 220));
    Di_text.setPosition(sf::Vector2f(285, 320));
    Eq_text.setPosition(sf::Vector2f(485, 220));


    // =================== ГЛАВНЫЙ ЦИКЛ ПРОГРАММЫ ===================
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // меняем цвет при наведении
        if (!clicked) {
            for (int i = 0; i < buttons.size(); i++) {
                if (mouseInButton(buttons[i], window) == true) {
                    buttons[i].setFillColor(buttonColor2);
                }
                else {
                    buttons[i].setFillColor(buttonColor1);
                }
            }
        }

        // Проверяем нажата ли кнопка
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !clicked) {
            clicked = true;

            // Проверка кнопок 0 - 9
            for (int i = 0; i <= 9; i++) {
                if (mouseInButton(buttons[i], window) == true) {
                    buttons[i].setFillColor(buttonColor3);
                    if (clickedEq == true) {
                        clickedEq = false;
                        number = 0;
                    }
                    number = number * 10 + i;
                    nm_text.setString(std::to_string(number));
                 }
            }

            // Кнопка стереть
            if (mouseInButton(buttons[10], window) == true) {
                buttons[10].setFillColor(buttonColor3);
                number = 0;
                nm_text.setString(std::to_string(number));
            }

            // Кнопка +
            if (mouseInButton(buttons[11], window) == true) {
                buttons[11].setFillColor(buttonColor3);
                numberA = number;
                number = 0;
                nm_text.setString(std::to_string(number));
                OP = operations::ADD;
            }

            // Кнопка -
            if (mouseInButton(buttons[12], window) == true) {
                buttons[12].setFillColor(buttonColor3);
                numberA = number;
                number = 0;
                nm_text.setString(std::to_string(number));
                OP = operations::SUBTRACT;
            }

            // Кнопка *
            if (mouseInButton(buttons[13], window) == true) {
                buttons[13].setFillColor(buttonColor3);
                numberA = number;
                number = 0;
                nm_text.setString(std::to_string(number));
                OP = operations::MULTIPLY;
            }

            // Кнопка /
            if (mouseInButton(buttons[14], window) == true) {
                buttons[14].setFillColor(buttonColor3);
                numberA = number;
                number = 0;
                nm_text.setString(std::to_string(number));
                OP = operations::DIVIDE;
            }

            // Кнопка =
            if (mouseInButton(buttons[15], window) == true) {
                buttons[15].setFillColor(buttonColor3);
                clickedEq = true;

                if (OP == operations::ADD) {
                    long long res = numberA + number;
                    number = res;
                    nm_text.setString(std::to_string(number));
                }
                if (OP == operations::SUBTRACT) {
                    long long res = numberA - number;
                    number = res;
                    nm_text.setString(std::to_string(number));
                }
                if (OP == operations::MULTIPLY) {
                    long long res = numberA * number;
                    number = res;
                    nm_text.setString(std::to_string(number));
                }
                if (OP == operations::DIVIDE) {
                    long double res = numberA / number;
                    number = res;
                    nm_text.setString(std::to_string(number));
                }
            }

        }
        else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && clicked) {
            clicked = false;
            for (int i = 0; i < buttons.size(); i++) {
                    buttons[i].setFillColor(buttonColor1);
            }
        }

        window.clear();
        

        // Отрисовываем в окне все элементы
        window.draw(nm_text);

        for (int i = 0; i < buttons.size(); i++)
        {
            window.draw(buttons[i]);
        }

        window.draw(b0_text);
        window.draw(b1_text);
        window.draw(b2_text);
        window.draw(b3_text);
        window.draw(b4_text);
        window.draw(b5_text);
        window.draw(b6_text);
        window.draw(b7_text);
        window.draw(b8_text);
        window.draw(b9_text);

        window.draw(cl_text);
        window.draw(Pl_text);
        window.draw(Mi_text);
        window.draw(Mu_text);
        window.draw(Di_text);
        window.draw(Eq_text);

        window.display();
    }
}