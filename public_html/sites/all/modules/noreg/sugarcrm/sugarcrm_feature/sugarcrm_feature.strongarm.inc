<?php
/**
 * @file
 * sugarcrm_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function sugarcrm_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_sugarcrm_account';
  $strongarm->value = 0;
  $export['comment_anonymous_sugarcrm_account'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_sugarcrm_account';
  $strongarm->value = 1;
  $export['comment_default_mode_sugarcrm_account'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_sugarcrm_account';
  $strongarm->value = '50';
  $export['comment_default_per_page_sugarcrm_account'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_sugarcrm_account';
  $strongarm->value = 1;
  $export['comment_form_location_sugarcrm_account'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_sugarcrm_account';
  $strongarm->value = '1';
  $export['comment_preview_sugarcrm_account'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_sugarcrm_account';
  $strongarm->value = 1;
  $export['comment_subject_field_sugarcrm_account'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_sugarcrm_account';
  $strongarm->value = '1';
  $export['comment_sugarcrm_account'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__sugarcrm_case';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__sugarcrm_case'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_sugarcrm_account';
  $strongarm->value = '0';
  $export['language_content_type_sugarcrm_account'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_sugarcrm_account';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_sugarcrm_account'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_sugarcrm_account';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_sugarcrm_account'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_sugarcrm_account';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_sugarcrm_account'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_sugarcrm_account';
  $strongarm->value = '1';
  $export['node_preview_sugarcrm_account'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_sugarcrm_account';
  $strongarm->value = 1;
  $export['node_submitted_sugarcrm_account'] = $strongarm;

  return $export;
}
