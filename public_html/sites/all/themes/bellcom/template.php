<?php

// Change CSS
function bellcom_css_alter( &$css ) {

    // System
    unset($css[drupal_get_path('module', 'system') . '/system.menus.css']);
    unset($css[drupal_get_path('module', 'system') . '/system.theme.css']);

    // Search
    unset($css[drupal_get_path('module', 'search') . '/search.css']);

    // Forum
    unset($css[drupal_get_path('module', 'forum') . '/forum.css']);

}

/**
 * Overrides theme_menu_tree().
 */
function bellcom_menu_tree__menu_header_top_menu(&$variables) {
    return '<ul>' . $variables['tree'] . '</ul>';
}


function bellcom_menu_link(array $variables) {

    $element = $variables['element'];
    $sub_menu = '';

    if ($element['#below']) {
        unset($element['#below']['#theme_wrappers']);
        $sub_menu = '<ul>' . drupal_render($element['#below']) . '</ul>';
    }

    $output = l($element['#title'], $element['#href'], $element['#localized_options']);

    if ( ( $element['#href'] == $_GET['q'] || ( $element['#href'] == '<front>' && drupal_is_front_page() ) ) && ( empty( $element['#localized_options']['language'] ) ) ) {
        $element['#attributes']['class'][] = 'active';
    }

    return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";

}