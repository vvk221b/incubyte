#include <iostream>
#include <vector>
#include <stack>

class Spacecraft {
public:
    virtual void move(char command) = 0;
    virtual void turn(char command) = 0;
    virtual void rotate(char command) = 0;
    virtual void executeCommands(const std::vector<char>& commands) = 0;
    virtual void printPositionAndDirection() = 0;
};

class AbstractSpacecraft : public Spacecraft {
protected:
    int x, y, z;
    char direction;
    std::stack<char> st;

public:
    AbstractSpacecraft(int initialX, int initialY, int initialZ, char initialDirection) 
        : x(initialX), y(initialY), z(initialZ), direction(initialDirection) {}

    std::string getCurrentPosition() {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
    }

    char getCurrentDirection() {
        return direction;
    }
};

class Chandrayaan3Spacecraft : public AbstractSpacecraft {
public:
    Chandrayaan3Spacecraft(int initialX, int initialY, int initialZ, char initialDirection)
        : AbstractSpacecraft(initialX, initialY, initialZ, initialDirection) {}

    void move(char command) override {
        switch (command) {
            case 'f':
                moveForward();
                break;
            case 'b':
                moveBackward();
                break;
        }
    }

    void turn(char command) override {
        switch (command) {
            case 'l':
                turnLeft();
                break;
            case 'r':
                turnRight();
                break;
        }
    }

    void rotate(char command) override {
        switch (command) {
            case 'u':
                rotateUp();
                break;
            case 'd':
                rotateDown();
                break;
        }
    }

    void executeCommands(const std::vector<char>& commands) override {
        for (char command : commands) {
            if (command == 'f' || command == 'b') {
                move(command);
            } else if (command == 'l' || command == 'r') {
                turn(command);
            } else if (command == 'u' || command == 'd') {
                rotate(command);
            }
        }
    }

    void printPositionAndDirection() override {
        std::cout << "Final Position: " << getCurrentPosition() << std::endl;
        std::cout << "Final Direction: " << getCurrentDirection() << std::endl;
    }

private:
    void moveForward() {
        switch (direction) {
            case 'N':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
            case 'U':
                z++;
                break;
            case 'D':
                z--;
                break;
        }
    }

    void moveBackward() {
        switch (direction) {
            case 'N':
                y--;
                break;
            case 'S':
                y++;
                break;
            case 'E':
                x--;
                break;
            case 'W':
                x++;
                break;
            case 'U':
                z--;
                break;
            case 'D':
                z++;
                break;
        }
    }

    void turnLeft() {
        switch (direction) {
            case 'N':
                direction = 'W';
                st.push('W');
                break;
            case 'S':
                direction = 'E';
                st.push('E');
                break;
            case 'E':
                direction = 'N';
                st.push('N');
                break;
            case 'W':
                direction = 'S';
                st.push('S');
                break;
            case 'U':
                while (!st.empty() && (st.top() != 'N' && st.top() != 'S' && st.top() != 'W' && st.top() != 'E')) {
                    st.pop();
                }
                if (!st.empty()) {
                    direction = st.top();
                    st.pop();
                }
                switch (direction) {
                    case 'N':
                        direction = 'W';
                        st.push('W');
                        break;
                    case 'S':
                        direction = 'E';
                        st.push('E');
                        break;
                    case 'E':
                        direction = 'N';
                        st.push('N');
                        break;
                    case 'W':
                        direction = 'S';
                        st.push('S');
                        break;
                }
                break;
            case 'D':
                while (!st.empty() && (st.top() != 'N' && st.top() != 'S' && st.top() != 'W' && st.top() != 'E')) {
                    st.pop();
                }
                if (!st.empty()) {
                    direction = st.top();
                    st.pop();
                }
                switch (direction) {
                    case 'N':
                        direction = 'W';
                        st.push('W');
                        break;
                    case 'S':
                        direction = 'E';
                        st.push('E');
                        break;
                    case 'E':
                        direction = 'N';
                        st.push('N');
                        break;
                    case 'W':
                        direction = 'S';
                        st.push('S');
                        break;
                }
                break;
        }
    }

    void turnRight() {
        switch (direction) {
            case 'N':
                direction = 'E';
                st.push('E');
                break;
            case 'S':
                direction = 'W';
                st.push('W');
                break;
            case 'E':
                direction = 'S';
                st.push('S');
                break;
            case 'W':
                direction = 'N';
                st.push('N');
                break;
            case 'U':
                while (!st.empty() && (st.top() != 'N' && st.top() != 'S' && st.top() != 'W' && st.top() != 'E')) {
                    st.pop();
                }
                if (!st.empty()) {
                    direction = st.top();
                    st.pop();
                }
                switch (direction) {
                    case 'N':
                        direction = 'E';
                        st.push('E');
                        break;
                    case 'S':
                        direction = 'W';
                        st.push('W');
                        break;
                    case 'E':
                        direction = 'S';
                        st.push('S');
                        break;
                    case 'W':
                        direction = 'N';
                        st.push('N');
                        break;
                }
                break;
            case 'D':
                while (!st.empty() && (st.top() != 'N' && st.top() != 'S' && st.top() != 'W' && st.top() != 'E')) {
                    st.pop();
                }
                if (!st.empty()) {
                    direction = st.top();
                    st.pop();
                }
                switch (direction) {
                    case 'N':
                        direction = 'E';
                        st.push('E');
                        break;
                    case 'S':
                        direction = 'W';
                        st.push('W');
                        break;
                    case 'E':
                        direction = 'S';
                        st.push('S');
                        break;
                    case 'W':
                        direction = 'N';
                        st.push('N');
                        break;
                }
                break;
        }
    }

    void rotateUp() {
        if (direction != 'U') {
            direction = 'U';
        }
    }

    void rotateDown() {
        if (direction != 'D') {
            direction = 'D';
        }
    }
};

int main() {
    std::cout << "Welcome to Chandrayaan 3 Lunar Craft Control!" << std::endl;

    int initialX, initialY, initialZ;
    char initialDirection;

    std::cout << "Enter the initial X position: ";
    std::cin >> initialX;
    std::cout << "Enter the initial Y position: ";
    std::cin >> initialY;
    std::cout << "Enter the initial Z position: ";
    std::cin >> initialZ;

    std::cout << "Enter the initial direction (N, S, E, W, U, D): ";
    std::cin >> initialDirection;

    Spacecraft* chandrayaan3 = new Chandrayaan3Spacecraft(initialX, initialY, initialZ, initialDirection);

    std::cout << "Enter the commands (e.g., f, r, u, b, l) as a single string: ";
    std::string inputCommands;
    std::cin >> inputCommands;

    std::vector<char> commands(inputCommands.begin(), inputCommands.end());

    chandrayaan3->executeCommands(commands);

    chandrayaan3->printPositionAndDirection();

    delete chandrayaan3;

    return 0;
}
