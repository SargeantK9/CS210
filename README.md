# CS210
The repository for my CS210 class at SNHU.

# What, Why, "AND HOW"

The project implements a console-based clock application that displays both a 12-hour and 24-hour clock simultaneously. The program allows users to adjust time through a menu interface while ensuring both time formats remain synchronized. The goal was to maintain accuracy between the two representations while minimizing redundant calculations.

Most of the processing logic is abstracted into functions.cpp, which separates the core logic from the user interface. This improves modularity and makes the program easier to maintain or expand.

Currently, the hours/minutes/seconds variables are modified by multiple functions, which could lead to unintended side effects. Encapsulating these variables within a class would improve security and maintainability by limiting direct access and making data flow more predictable.
The most challenging part of the code for me was making the display. I wanted it to be reactive so designers could modify the text segments without having to completely reformat the menu design.

In response to challenges like this, I follow a reference flow path starting with documentation, then ChatGPT and Stack Overflow. I start in the documentation to gain exposure to the designers’ words first. I use ChatGPT to rephrase documentation if I struggle to understand a concept as written. For complex implementations I don’t understand, I rely on Stack Overflow. Going forward, I intend to collaborate more with direct peers.

This was the first project where I really felt like I was deliberately embracing abstraction and could see my code becoming more abstract. Separating logic into reusable functions will be valuable in future programming assignments because it allows complex programs to be broken into manageable components.

I built many of the display sections as reactive so they theoretically won’t need to be adjusted and can be used in other projects. I also commented heavily and put constants at the top, using industry standard formatting to ensure ease of identification. I designed the program so future developers can modify most of the transient parameters easily whilst maintaining the integrity of the overall program.

