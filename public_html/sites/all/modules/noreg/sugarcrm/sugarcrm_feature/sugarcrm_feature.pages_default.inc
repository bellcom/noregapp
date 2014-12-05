<?php
/**
 * @file
 * sugarcrm_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function sugarcrm_feature_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_edit_panel_context';
  $handler->task = 'user_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'sugarcrm user cases',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Node from User (on User: Sugarcrm account [field_sugarcrm_account])',
        'keyword' => 'node',
        'name' => 'entity_from_field:field_sugarcrm_account-user-node',
        'delta' => 0,
        'context' => 'argument_user_edit_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'context_exists',
          'settings' => array(
            'exists' => '1',
          ),
          'context' => 'relationship_entity_from_field:field_sugarcrm_account-user-node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 1,
          1 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'top',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'top' => array(
        'type' => 'region',
        'title' => 'top',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'top' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd2b0f92e-fad7-458d-864d-c74b2ae16059';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ae6a96c8-a79f-446d-a171-b30693cc772b';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'sugarcrm_user_cases-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'relationship_entity_from_field:field_sugarcrm_account-user-node_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ae6a96c8-a79f-446d-a171-b30693cc772b';
    $display->content['new-ae6a96c8-a79f-446d-a171-b30693cc772b'] = $pane;
    $display->panels['center'][0] = 'new-ae6a96c8-a79f-446d-a171-b30693cc772b';
    $pane = new stdClass();
    $pane->pid = 'new-7f00458f-962a-44dd-a3fe-b30b74a4278c';
    $pane->panel = 'top';
    $pane->type = 'form';
    $pane->subtype = 'form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_user_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7f00458f-962a-44dd-a3fe-b30b74a4278c';
    $display->content['new-7f00458f-962a-44dd-a3fe-b30b74a4278c'] = $pane;
    $display->panels['top'][0] = 'new-7f00458f-962a-44dd-a3fe-b30b74a4278c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ae6a96c8-a79f-446d-a171-b30693cc772b';
  $handler->conf['display'] = $display;
  $export['user_edit_panel_context'] = $handler;

  return $export;
}
