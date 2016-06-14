<?php

/**
 * @file
 * Vocabulary validation admin file.
 */

/**
 * Implements hook_form().
 */
function _vocabulary_validation_admin_form($form, &$form_state) {
  $form['vocabulary_validation_rule'] = array(
    '#type' => 'fieldset',
    '#title' => t('Vocabulary condition'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );
  $vocabulary_validation_rule = variable_get('vocabulary_validation_rule', array());
  $form['vocabulary_validation_rule']['blacklist_char'] = array(
    '#type' => 'textarea',
    '#default_value' => isset($vocabulary_validation_rule['blacklist_char']) ? $vocabulary_validation_rule['blacklist_char'] : '',
    '#title' => t('Blacklist Characters/Words'),
    '#description' => '<p>' . t("Comma separated characters or words to avoid while saving vocabulary. Example: !,@,#,$,%,^,&,*,(,),1,2,3,have,has,were,aren't.") . '</p>' . '<p>' . t('If any of the blacklisted characters and/or words found in vocabulary ,would return validation error on vocabulary save.') . '</p>',
  );
  $form['vocabulary_validation_rule']['min_char'] = array(
    '#type' => 'textfield',
    '#title' => t("Minimum characters"),
    '#required' => TRUE,
    '#description' => t("Minimum number of characters vocabulary should contain"),
    '#size' => 12,
    '#maxlength' => 3,
    '#default_value' => isset($vocabulary_validation_rule['min_char']) ? $vocabulary_validation_rule['min_char'] : '1',
  );
  $form['vocabulary_validation_rule']['max_char'] = array(
    '#type' => 'textfield',
    '#title' => t("Maximum characters"),
    '#required' => TRUE,
    '#description' => t("Maximum number of characters vocabulary should contain"),
    '#size' => 12,
    '#maxlength' => 3,
    '#default_value' => isset($vocabulary_validation_rule['max_char']) ? $vocabulary_validation_rule['max_char'] : '255',
  );
  $form['#validate'][] = '_vocabulary_validation_admin_form_validate';
  return system_settings_form($form);
}

/**
 * The validation function for _vocabulary_validation_admin_form form.
 */
function _vocabulary_validation_admin_form_validate($form, &$form_state) {
  $max = $form_state['values']['vocabulary_validation_rule']['max_char'];
  // Maximum characters field is numerical.
  if (!is_numeric($max)) {
    form_set_error('max_char', t("Maximum characters should be Numerical"));
  }
  // Validate field should be between 0 and 256.
  if ($max <= 0 || $max > 255) {
    form_set_error('max_char', t("Minimum and maximum value should be between 0 and 256"));
  }
  $min = $form_state['values']['vocabulary_validation_rule']['min_char'];
  // Minimum characters field is numerical.
  if (!is_numeric($min)) {
    form_set_error('min_char', t("Minimum characters should be Numerical"));
  }
  // Minimum characters field is greater than 1.
  if ($min < 1) {
    form_set_error('min_char', t("These value should be more than 1"));
  }
  // Validate min is less than max value.
  if ($min > $max) {
    form_set_error('min_char', t("Minimum length should not be more than Max length"));
  }
}
