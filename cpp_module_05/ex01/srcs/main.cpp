/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:25:22 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/29 21:28:17 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

#include <iostream>
const std::string colorGreen = "\033[33m";
const std::string colorPurple = "\033[35m";
const std::string colorRed = "\033[31m";
const std::string colorBlue = "\033[34m";

void printColored(const std::string& message, const std::string& color) {
	std::cout << color << message << "\033[0m" << std::endl;
}

void invalidFormsTryCatch(std::string name, int signGrade, int execGrade) {
	try {
		Form form1(name, signGrade, execGrade);
		std::cout << "Form created successfully: " << form1 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void createInvalidForms() {
	printColored("TESTING INVALID FORM CREATION", colorPurple);
	
	printColored("Creating Form: Invalid2, signGrade: 151, execGrade: 10", colorGreen);
	invalidFormsTryCatch("Invalid2", 151, 10);

	printColored("Creating Form: Invalid2, signGrade: 10, execGrade: 151", colorGreen);
	invalidFormsTryCatch("Invalid2", 10, 151);

	printColored("Creating Form: Invalid2, signGrade: 0, execGrade: 1", colorGreen);
	invalidFormsTryCatch("Invalid2", 0, 1);

	printColored("Creating Form: Invalid2, signGrade: 1, execGrade: 0", colorGreen);
	invalidFormsTryCatch("Invalid2", 1, 0);
	
	std::cout << std::endl;
}

void testFormSigning() {
	printColored("TESTING FORM SIGNING", colorPurple);
	
	// Test case 1: Bureaucrat with sufficient grade to sign
	printColored("TEST CASE 1: Bureaucrat can sign form", colorGreen);
	try {
		Bureaucrat bob("Bob", 50);
		Form taxForm("Tax Form", 100, 100);
		
		std::cout << bob << std::endl;
		std::cout << taxForm << std::endl;
		
		bob.signForm(taxForm);
		std::cout << "After signing: " << taxForm << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	// Test case 2: Bureaucrat with insufficient grade
	printColored("TEST CASE 2: Bureaucrat cannot sign form (too low grade)", colorRed);
	try {
		Bureaucrat intern("Intern", 150);
		Form secretDocument("Secret Document", 10, 5);
		
		std::cout << intern << std::endl;
		std::cout << secretDocument << std::endl;
		
		intern.signForm(secretDocument);
		std::cout << "After signing attempt: " << secretDocument << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	// Test case 3: Edge case (minimum required grade)
	printColored("TEST CASE 3: Bureaucrat with exact required grade", colorBlue);
	try {
		Bureaucrat manager("Manager", 25);
		Form projectForm("Project Approval", 25, 25);
		
		std::cout << manager << std::endl;
		std::cout << projectForm << std::endl;
		
		manager.signForm(projectForm);
		std::cout << "After signing: " << projectForm << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << std::endl;
}

void testBureaucratOperations() {
	printColored("TESTING BUREAUCRAT OPERATIONS", colorPurple);
	
	try {
		// Create a bureaucrat
		Bureaucrat chief("Chief", 5);
		std::cout << "Initial: " << chief << std::endl;
		
		// Test increment
		printColored("Testing increment:", colorGreen);
		chief.incrementGrade();
		std::cout << "After increment: " << chief << std::endl;
		
		chief.incrementGrade();
		std::cout << "After increment: " << chief << std::endl;
		
		// Test decrement
		printColored("Testing decrement:", colorRed);
		chief.decrementGrade();
		std::cout << "After decrement: " << chief << std::endl;
		
		chief.decrementGrade();
		std::cout << "After decrement: " << chief << std::endl;
		
		// Try to exceed boundaries
		printColored("Testing boundaries:", colorBlue);
		Bureaucrat executive("Executive", 1);
		std::cout << executive << std::endl;
		
		try {
			executive.incrementGrade(); // Should throw exception
		} catch(std::exception &e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
		
		Bureaucrat clerk("Clerk", 150);
		std::cout << clerk << std::endl;
		
		try {
			clerk.decrementGrade(); // Should throw exception
		} catch(std::exception &e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << std::endl;
}

void testSignFormWithVariousScenarios() {
    printColored("TESTING BUREAUCRAT::SIGNFORM IN VARIOUS SCENARIOS", colorPurple);
    
    // Scenario 1: Signing an already signed form
    printColored("SCENARIO 1: Attempting to sign an already signed form", colorGreen);
    try {
        Bureaucrat director("Director", 5);
        Form contract("Employment Contract", 10, 10);
        
        std::cout << "Initial form state: " << contract << std::endl;
        
        // First signing attempt
        director.signForm(contract);
        
        // Second signing attempt on already signed form
        printColored("Attempting to sign already signed form:", colorBlue);
        director.signForm(contract);
    }
    catch (std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    
    // Scenario 2: Multiple bureaucrats trying to sign the same form
    printColored("\nSCENARIO 2: Multiple bureaucrats with different grades trying to sign the same form", colorGreen);
    try {
        Form importantForm("Budget Approval", 50, 30);
        
        Bureaucrat lowLevel("Intern", 100);
        Bureaucrat midLevel("Manager", 40);
        Bureaucrat highLevel("CEO", 1);
        
        std::cout << "Form: " << importantForm << std::endl;
        std::cout << "Bureaucrats:\n" << lowLevel << "\n" << midLevel << "\n" << highLevel << std::endl;
        
        printColored("Low-level employee attempt:", colorRed);
        lowLevel.signForm(importantForm);
        
        printColored("Mid-level employee attempt:", colorBlue);
        midLevel.signForm(importantForm);
        
        printColored("High-level employee attempt:", colorBlue);
        highLevel.signForm(importantForm);
    }
    catch (std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    
    // Scenario 3: Edge case - Bureaucrat with exactly the required grade
    printColored("\nSCENARIO 3: Bureaucrat with exactly the required grade", colorGreen);
    try {
        Form strictForm("Classified Document", 42, 42);
        Bureaucrat exactGrade("Agent42", 42);
        
        std::cout << "Form: " << strictForm << std::endl;
        std::cout << "Bureaucrat: " << exactGrade << std::endl;
        
        exactGrade.signForm(strictForm);
        
        // Test that the form is actually signed
        std::cout << "Form state after signing: " << strictForm << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    
    // Scenario 4: Bureaucrat just one grade too low
    printColored("\nSCENARIO 4: Bureaucrat just one grade too low", colorRed);
    try {
        Form strictForm("Top Secret", 20, 10);
        Bureaucrat almostQualified("AlmostThere", 21);
        
        std::cout << "Form: " << strictForm << std::endl;
        std::cout << "Bureaucrat: " << almostQualified << std::endl;
        
        almostQualified.signForm(strictForm);
        
        // Promote and try again
        printColored("After promotion:", colorGreen);
        almostQualified.incrementGrade();
        std::cout << "Bureaucrat after promotion: " << almostQualified << std::endl;
        
        almostQualified.signForm(strictForm);
    }
    catch (std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}


void waitForEnter(const std::string& message) {
	std::cout << message << " Press Enter to continue..." << std::endl;
	std::cin.get();
}

int main() {
	waitForEnter("Ready to test invalid form creation.");
	createInvalidForms();

	waitForEnter("Ready to test form signing.");
	testFormSigning();

	waitForEnter("Ready to test bureaucrat operations.");
	testBureaucratOperations();

	waitForEnter("Ready to test Bureaucrat::signForm in various scenarios.");
	testSignFormWithVariousScenarios();
	return 0;
}