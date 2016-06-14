Vocabulary Validation
---------------------

CONTENTS OF THIS FILE
---------------------

  * Introduction
  * Installation
  * Configuration
  * UnInstallation
  * Maintainers

INTRODUCTION:
------------
This module validates 'vocabulary name' by set of rules like
- restricting numbers
- some allowed special characters like (- . _)
- block special words and minimum/maximum characters etc

INSTALLATION:
-------------
1. Copy 'vocabulary_validation' folder to modules directory.
2. At admin/modules enable the 'vocabulary_validation' module.

CONFIGURATION:
-------------
1. Once the module is activated, go to admin/config/people/vocabulary-validation
2. enter blacklist characters and/or words in given textarea
3. Enter minimum characters value
4. Enter maximum characters value
5. Click on 'Save Configuration' button
6. Add one vocabulary and test the validations

UN-INSTALLATION:
----------------
To un-install the module,
1) Go to admin/modules
2) Find 'vocabulary_validation' in OTHER package
3) Un-check the checkbox and save.
4) Then go to admin/modules/uninstall
5) Un-check the checkbox and click 'uninstall'.

MAINTAINERS:
------------
Hiraman Patil - https://www.drupal.org/u/hiramanpatil
