<?php

  include_once dirname(__FILE__) . '/includes/common.inc';


  /**
   * Implements hook_form_FORM_ID_alter().
   *
   * @param $form
   *   The form.
   * @param $form_state
   *   The form state.
   */
  function bellcom_form_system_theme_settings_alter(&$form, $form_state, $form_id = NULL) {

    //
    if (isset($form_id)) {
      return;
    }

    // Include settings file.
    bellcom_include('bellcom', 'includes/settings.inc');

    // Alter settings form.
    _bellcom_settings_form($form, $form_state);

  }