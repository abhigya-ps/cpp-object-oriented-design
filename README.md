## Object Oriented Design in C++

### 1. [Playing Cards](https://github.com/abhigya-ps/cpp-object-oriented-design/tree/main/Playing-Cards)
Implemented a class to store a simple deck of playing cards which can be expanded to various other card games through polymorphism.
- The Card class stores the suit and rank of the card with methods to view and change those values.
- The Deck class stores a collection of cards in a double-ended queue (deque) with methods to shuffle the deck and view the cards. The deque also helps in retrieving a card from the top of the deck and pushing it to the bottom of the deck or discarding it.


### 2. [Vending Machine System](https://github.com/abhigya-ps/cpp-object-oriented-design/tree/main/finite-state-machine)
Developed a vending machine system based on the principles of finite state machines and user feedback loop. A finite state machine responds to inputs based on previous inputs or events. Finite state machines are designed to allow users to reach their end goal in a directed, step-by-step fashion.

A simple vending machine has 4 states or steps to follow:
1. <i>Initial State</i> - the first step is to select a drink to purchase
2. <i>Quantity State</i> - the second step is to select the number of drinks (some vending machines may not have this option)
3. <i>Calculate State</i> - the next step is to calculate the total price, given the drink isn't out of stock
4. <i>Update State</i> - the final step is confirm the purchase with the user, handle the change to return, and update the vending machine's stock

<p align="center">
  <img src="/finite-state-machine/media/fsm-diagram.JPG" alt="home_menu" width="40%" align="center"> 
 </p>

### 3. [Combat Simulator](https://github.com/abhigya-ps/cpp-object-oriented-design/tree/main/hero-oop)
Created a class to generate players from opposing sides but with the same base properties and methods using inheritance and encapsulation. Also, built a function that simulates multi-round battle between the two sides and returns the number of rounds won by each side out of a predefined number of total rounds.

- Each player has a category it belongs to (protagonist or antagonist), health and shield values, method to reduce its health when attacked, and a boolean that determines whether the player has survived or not.
- The battle simulator lets both sides attack the other side turn by turn. During each turn, a player takes a hit depending on a predefined probability of the hit successfully landing. If the hit lands, the player's health drops and eventually dies. The team with no surviving players loses that round. And the team with the higher number of victorious rounds wins the battle.
