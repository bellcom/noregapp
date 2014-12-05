<?php
class SugarAccount {
  private $assigned_user_name;
  private $modified_by_name;
  private $created_by_name;
  private $id;
  private $name;
  private $date_entered;
  private $date_modified;
  private $modified_user_id;
  private $modified_user_name;
  private $created_by;
  private $description;
  private $deleted;
  private $assigned_user_id;
  private $account_type;
  private $industry;
  private $annual_revenue;
  private $phone_fax;
  private $billing_address_street;
  private $billing_address_city;
  private $billing_address_state;
  private $billing_address_postalcode;
  private $billing_address_country;
  private $rating;
  private $phone_office;
  private $phone_alternate;
  private $website;
  private $ownership;
  private $employees;
  private $ticker_symbol;
  private $shipping_address_street;
  private $shipping_address_city;
  private $shipping_address_state;
  private $shipping_address_postalcode;
  private $shipping_address_country;
  private $email1;
  private $parent_id;
  private $sic_code;
  private $parent_name;
  private $campaign_id;
  private $campaign_name;
  private $cvr_nummer_c;
  private $crm1_link_c;
  private $map_c;

  function __construct($data)
  {
    foreach ($data as $d) {
      $this->$d['name'] = $d['value'];
    }

  }

  function __set($name, $value)
  {
    if(property_exists($this, $name))
      $this->$name = $value;
  }

  function __get($name)
  {
    if(property_exists($this, $name))
      return $this->$name;
  }

} 