// soj: 10629. Robot
// Thu Dec 25, 2014--------Shawn Chow
struct Position {
  int x;
  int y;
};

class Robot {
public:
  
  Robot();
  /* default constructor, initialize at (0,0) */
  
  Robot(Position pos);     /* initialize at pos */
  
  void Move(char Dir);     /* Dir could be 'N', 'E', 'S', 'W', for other characters, the robot don’t move */
  
  Position GetPosition();        /* return current position */
  
private:
  
  Position currentPos;
};

Robot::Robot() {
  currentPos.x = currentPos.y = 0;
}

Robot::Robot(Position pos) {
  currentPos = pos;
}

void Robot::Move(char dir) {
  if ('N' == dir) {
    ++currentPos.y;
  } else if ('E' == dir) {
    ++currentPos.x;
  } else if ('S' == dir) {
    --currentPos.y;
  } else if ('W' == dir) {
    --currentPos.x;
  }
}

Position Robot::GetPosition() {
  return currentPos;
}

int main(int argc, char *argv[]) {
  
  return 0;
}

