<?php


function _bellcom_settings_form(&$form, $form_state) {


  // Theme settings
  drupal_add_css(drupal_get_path('theme', 'bellcom') . '/css/theme-settings.css');


  // Vertical tabs
  $form['options'] = array(
    '#type' => 'vertical_tabs',
    '#default_tab' => 'main',
    '#weight' => '-20',
    '#prefix' => '<h2><small>' . t('Bellcom theme settings') . '</small></h2>',
    '#title' => t('Bellcom theme settings'),
  );



  /*
  |--------------------------------------------------------------------------
  | Main settings
  |--------------------------------------------------------------------------
  |
  | Sets all necessary options to save data.
  |
  */

  // Fieldset
  $form['options']['main'] = array(
    '#type' => 'fieldset',
    '#title' => t('Main settings'),
  );




  /*
  |--------------------------------------------------------------------------
  | Page layout
  |--------------------------------------------------------------------------
  |
  | Sets all necessary options to save data.
  |
  */

  // Fieldset
  $form['options']['layout'] = array(
    '#type' => 'fieldset',
    '#title' => t('Page layout'),
  );

  // Top bar.
  $form['options']['layout']['top_bar'] = array(
    '#type' => 'fieldset',
    '#title' => 'Top bar',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Top bar - contact information
  $form['options']['layout']['top_bar']['contact_information'] = array(
    '#type' => 'select',
    '#title' => t('Show contact information'),
    '#options' => array(
      1 => t('No, hide them.'),
      2 => t('Left side'),
      3 => t('Right side')
    ),
    '#default_value' => theme_get_setting('contact_information'),
  );

  // Top bar - social links
  $form['options']['layout']['top_bar']['social_links'] = array(
    '#type' => 'select',
    '#title' => t('Show social links'),
    '#options' => array(
      1 => t('No, hide them.'),
      2 => t('Left side'),
      3 => t('Right side')
    ),
    '#default_value' => theme_get_setting('social_links'),
  );



  // Navigation
  $form['options']['layout']['navigation'] = array(
    '#type' => 'fieldset',
    '#title' => 'Navigation',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Navigation - login account links
  $form['options']['layout']['navigation']['login_account_links'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show login and user account links'),
    '#default_value' => theme_get_setting('login_account_links'),
    '#description'   => t("Links displayed in right side of navigation"),
  );



  // Footer
  $form['options']['layout']['footer'] = array(
    '#type' => 'fieldset',
    '#title' => 'Footer',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  // Copyright year
  $form['options']['layout']['footer']['copyright_year'] = array(
    '#type' => 'textfield',
    '#title' => t('Copyright (from) year'),
    '#default_value' => theme_get_setting('copyright_year'),
  );



  /*
  |--------------------------------------------------------------------------
  | Contact information
  |--------------------------------------------------------------------------
  |
  | Sets all necessary options to save data.
  |
  */

  // Fieldset
  $form['options']['contact_information'] = array(
    '#type' => 'fieldset',
    '#title' => t('Contact information'),
  );

  // Owner name
  $form['options']['contact_information']['owner_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Owner name'),
    '#default_value' => theme_get_setting('owner_name'),
  );

  // Address
  $form['options']['contact_information']['address'] = array(
    '#type' => 'textfield',
    '#title' => t('Address'),
    '#default_value' => theme_get_setting('address'),
  );

  // Zipcode
  $form['options']['contact_information']['zipcode'] = array(
    '#type' => 'textfield',
    '#title' => t('Zipcode'),
    '#default_value' => theme_get_setting('zipcode'),
  );

  // City
  $form['options']['contact_information']['city'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
    '#default_value' => theme_get_setting('city'),
  );

  // Phone number
  $form['options']['contact_information']['phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Phone number'),
    '#description' => t('Remember: you need to use the correct format. Ex.: 004570260085'),
    '#default_value' => theme_get_setting('phone'),
  );

  // Phone number - readable
  $form['options']['contact_information']['phone_readable'] = array(
    '#type' => 'textfield',
    '#title' => t('Readable phone number'),
    '#description' => t('The textual representation of your phone number.'),
    '#default_value' => theme_get_setting('phone_readable'),
  );

  // E-mail address
  $form['options']['contact_information']['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email address'),
    '#default_value' => theme_get_setting('email'),
  );



  /*
  |--------------------------------------------------------------------------
  | Social links
  |--------------------------------------------------------------------------
  |
  | Sets all necessary options to save data.
  |
  */


  // Fieldset
  $form['options']['social_links'] = [
    '#type'             => 'fieldset',
    '#title'            => t('Social links'),
  ];


  // Facebook
  $form['options']['social_links']['facebook'] = [
    '#type'             => 'checkbox',
    '#title'            => t('Facebook'),
    '#default_value'    => theme_get_setting('facebook'),
  ];
  $form['options']['social_links']['facebook_uri'] = [
    '#type'             => 'textfield',
    '#title'            => t('Facebook link'),
    '#default_value'    => theme_get_setting('facebook_uri'),
    '#states'           => [
      // Hide the options when the cancel notify checkbox is disabled.
      'visible'         => [
        ':input[name="facebook"]' => [
          'checked'     => true
        ],
      ],
    ],
  ];
  $form['options']['social_links']['facebook_tooltip_text'] = [
    '#type'             => 'textfield',
    '#title'            => t('Tooltip text'),
    '#default_value'    => theme_get_setting('facebook_tooltip_text'),
    '#states'           => [
      // Hide the options when the cancel notify checkbox is disabled.
      'visible'         => [
        ':input[name="facebook"]' => [
          'checked'     => true
        ],
      ],
    ],
  ];


  // Twitter
  $form['options']['social_links']['twitter'] = [
    '#type' => 'checkbox',
    '#title' => t('Twitter'),
    '#default_value' => theme_get_setting('twitter'),
  ];
  $form['options']['social_links']['twitter_uri'] = [
    '#type'             => 'textfield',
    '#title'            => t('Twitter link'),
    '#default_value'    => theme_get_setting('twitter_uri'),
    '#states'           => [
      // Hide the options when the cancel notify checkbox is disabled.
      'visible'         => [
        ':input[name="twitter"]' => [
          'checked'     => true
        ],
      ],
    ],
  ];
  $form['options']['social_links']['twitter_tooltip_text'] = [
    '#type'             => 'textfield',
    '#title'            => t('Tooltip text'),
    '#default_value'    => theme_get_setting('twitter_tooltip_text'),
    '#states'           => [
      // Hide the options when the cancel notify checkbox is disabled.
      'visible'         => [
        ':input[name="twitter"]' => [
          'checked'     => true
        ],
      ],
    ],
  ];


  // Instagram
  $form['options']['social_links']['instagram'] = [
    '#type' => 'checkbox',
    '#title' => t('Instagram'),
    '#default_value' => theme_get_setting('instagram'),
  ];
  $form['options']['social_links']['instagram_uri'] = [
    '#type'             => 'textfield',
    '#title'            => t('Instagram link'),
    '#default_value'    => theme_get_setting('instagram_uri'),
    '#states'           => [
      // Hide the options when the cancel notify checkbox is disabled.
      'visible'         => [
        ':input[name="instagram"]' => [
          'checked'     => true
        ],
      ],
    ],
  ];
  $form['options']['social_links']['instagram_tooltip_text'] = [
    '#type'             => 'textfield',
    '#title'            => t('Tooltip text'),
    '#default_value'    => theme_get_setting('instagram_tooltip_text'),
    '#states'           => [
      // Hide the options when the cancel notify checkbox is disabled.
      'visible'         => [
        ':input[name="instagram"]' => [
          'checked'     => true
        ],
      ],
    ],
  ];


  // LinkedIn
  $form['options']['social_links']['linkedin'] = [
    '#type' => 'checkbox',
    '#title' => t('LinkedIn'),
    '#default_value' => theme_get_setting('linkedin'),
  ];
  $form['options']['social_links']['linkedin_uri'] = [
    '#type'             => 'textfield',
    '#title'            => t('LinkedIn link'),
    '#default_value'    => theme_get_setting('linkedin_uri'),
    '#states'           => [
      // Hide the options when the cancel notify checkbox is disabled.
      'visible'         => [
        ':input[name="linkedin"]' => [
          'checked'     => true
        ],
      ],
    ],
  ];
  $form['options']['social_links']['linkedin_tooltip_text'] = [
    '#type'             => 'textfield',
    '#title'            => t('Tooltip text'),
    '#default_value'    => theme_get_setting('linkedin_tooltip_text'),
    '#states'           => [
      // Hide the options when the cancel notify checkbox is disabled.
      'visible'         => [
        ':input[name="linkedin"]' => [
          'checked'     => true
        ],
      ],
    ],
  ];


  // Pinterest
  $form['options']['social_links']['pinterest'] = [
    '#type' => 'checkbox',
    '#title' => t('Pinterest'),
    '#default_value' => theme_get_setting('pinterest'),
  ];
  $form['options']['social_links']['pinterest_uri'] = [
    '#type'             => 'textfield',
    '#title'            => t('Pinterest link'),
    '#default_value'    => theme_get_setting('pinterest_uri'),
    '#states'           => [
      // Hide the options when the cancel notify checkbox is disabled.
      'visible'         => [
        ':input[name="pinterest"]' => [
          'checked'     => true
        ],
      ],
    ],
  ];
  $form['options']['social_links']['pinterest_tooltip_text'] = [
    '#type'             => 'textfield',
    '#title'            => t('Tooltip text'),
    '#default_value'    => theme_get_setting('pinterest_tooltip_text'),
    '#states'           => [
      // Hide the options when the cancel notify checkbox is disabled.
      'visible'         => [
        ':input[name="pinterest"]' => [
          'checked'     => true
        ],
      ],
    ],
  ];


  // Vimeo
  $form['options']['social_links']['vimeo'] = [
    '#type' => 'checkbox',
    '#title' => t('Vimeo'),
    '#default_value' => theme_get_setting('vimeo'),
  ];
  $form['options']['social_links']['vimeo_uri'] = [
    '#type'             => 'textfield',
    '#title'            => t('Vimeo link'),
    '#default_value'    => theme_get_setting('vimeo_uri'),
    '#states'           => [
      // Hide the options when the cancel notify checkbox is disabled.
      'visible'         => [
        ':input[name="vimeo"]' => [
          'checked'     => true
        ],
      ],
    ],
  ];
  $form['options']['social_links']['vimeo_tooltip_text'] = [
    '#type'             => 'textfield',
    '#title'            => t('Tooltip text'),
    '#default_value'    => theme_get_setting('vimeo_tooltip_text'),
    '#states'           => [
      // Hide the options when the cancel notify checkbox is disabled.
      'visible'         => [
        ':input[name="vimeo"]' => [
          'checked'     => true
        ],
      ],
    ],
  ];


  // Youtube
  $form['options']['social_links']['youtube'] = [
    '#type' => 'checkbox',
    '#title' => t('Youtube'),
    '#default_value' => theme_get_setting('youtube'),
  ];
  $form['options']['social_links']['youtube_uri'] = [
    '#type'             => 'textfield',
    '#title'            => t('Youtube link'),
    '#default_value'    => theme_get_setting('youtube_uri'),
    '#states'           => [
      // Hide the options when the cancel notify checkbox is disabled.
      'visible'         => [
        ':input[name="youtube"]' => [
          'checked'     => true
        ],
      ],
    ],
  ];
  $form['options']['social_links']['youtube_tooltip_text'] = [
    '#type'             => 'textfield',
    '#title'            => t('Tooltip text'),
    '#default_value'    => theme_get_setting('youtube_tooltip_text'),
    '#states'           => [
      // Hide the options when the cancel notify checkbox is disabled.
      'visible'         => [
        ':input[name="youtube"]' => [
          'checked'     => true
        ],
      ],
    ],
  ];

}