/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonFormDemo.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhojazo <zkhojazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 08:41:59 by zkhojazo          #+#    #+#             */
/*   Updated: 2025/05/30 09:13:09 by zkhojazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mainHeader.hpp"

void testPresidentialFormWithDifferentGrades() {
	printColored("\n=== TESTING PRESIDENTIAL PARDON FORM WITH VARIOUS GRADES ===", colorBlue);
	
	PresidentialPardonForm pardonForm("Criminal");
	
	// Test with various bureaucrat grades
	Bureaucrat president("President", 1);     // Highest possible grade
	Bureaucrat minister("Minister", 5);       // Can execute (exec grade is 5)
	Bureaucrat secretary("Secretary", 6);     // Cannot execute (too low) but can sign
	Bureaucrat assistant("Assistant", 25);    // Can sign (sign grade is 25)
	Bureaucrat intern("Intern", 26);          // Cannot sign (too low)
	
	printColored("Form status before any action:", colorGreen);
	std::cout << pardonForm << std::endl;
	
	// Test signing with different grades
	printColored("\nTesting form signing with different bureaucrats:", colorGreen);
	try {
		intern.signForm(pardonForm);
	} catch (std::exception &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	
	// Secretary should be able to sign
	assistant.signForm(pardonForm);
	std::cout << "After assistant tried to sign: " << pardonForm << std::endl;
	
	// Test execution with different grades
	printColored("\nTesting form execution with different bureaucrats:", colorGreen);
	
	// Attempt execution with unsigned form
	executeTryCatch(pardonForm, president);
	
	// Now sign the form and try again
	minister.signForm(pardonForm);
	std::cout << "Form after signing: " << pardonForm << std::endl;
	
	// Test execution with various grades
	printColored("\nAttempting execution with various grades:", colorPurple);
	executeTryCatch(pardonForm, intern);      // Too low grade
	executeTryCatch(pardonForm, assistant);   // Too low grade  
	executeTryCatch(pardonForm, secretary);   // Just 1 below required
	executeTryCatch(pardonForm, minister);    // Exactly at required grade
	executeTryCatch(pardonForm, president);   // Above required grade
}

void testBorderlineCases() {
	printColored("\n=== TESTING BORDERLINE CASES ===", colorBlue);
	
	// Create form with default target
	PresidentialPardonForm defaultForm;
	std::cout << "Default form's target: " << defaultForm.getTarget() << std::endl;
	
	// Test with exactly required grades
	Bureaucrat exactSigner("ExactSigner", 25);   // Exactly the signing grade
	Bureaucrat exactExecutor("ExactExecutor", 5); // Exactly the execution grade
	
	printColored("\nTesting with exact required grades:", colorGreen);
	exactSigner.signForm(defaultForm);
	std::cout << "Form after signing with exact grade: " << defaultForm << std::endl;
	executeTryCatch(defaultForm, exactExecutor);
	
	// Test multiple sign attempts
	printColored("\nTesting multiple signing attempts:", colorGreen);
	std::cout << "Before second signing attempt: " << defaultForm << std::endl;
	exactSigner.signForm(defaultForm); // Try to sign again
	std::cout << "After second signing attempt: " << defaultForm << std::endl;
	
	// Test execution on already executed form
	printColored("\nExecuting already executed form:", colorGreen);
	executeTryCatch(defaultForm, exactExecutor); // Should work fine, no state change happens
}

void testExceptionHandling() {
	printColored("\n=== TESTING EXCEPTION HANDLING ===", colorRed);
	
	PresidentialPardonForm pardonForm("Convict");
	
	// Test form before signing
	printColored("\nAttempting to execute unsigned form:", colorGreen);
	try {
		Bureaucrat president("President", 1);
		pardonForm.execute(president);
	} catch (std::exception &e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}
	
	// Test with signing but insufficient execution grade
	printColored("\nSigning form but executing with insufficient grade:", colorGreen);
	try {
		Bureaucrat minister("Minister", 5);
		Bureaucrat clerk("Clerk", 100);
		
		minister.signForm(pardonForm);
		std::cout << "Form signed successfully: " << pardonForm << std::endl;
		
		pardonForm.execute(clerk);
	} catch (std::exception &e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}
}
