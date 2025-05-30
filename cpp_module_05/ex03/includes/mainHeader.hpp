#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

#include <iostream>


const std::string colorGreen = "\033[33m";
const std::string colorPurple = "\033[35m";
const std::string colorRed = "\033[31m";
const std::string colorBlue = "\033[34m";

// helperFunction.cpp
void printColored(const std::string& message, const std::string& color);
void waitForEnter(const std::string& message);
void executeTryCatch(AForm &form, Bureaucrat &br);

// PresidentialPardonFormDemo

void testPresidentialFormWithDifferentGrades();
void testBorderlineCases();
void testExceptionHandling();

// Add these function declarations:

// RobotomyRequestFormDemo.cpp
void testRobotomyRequestFormWithDifferentGrades();
void testRobotomyBorderlineCases();
void testRobotomyExceptionHandling();
void robotomyDemo();
