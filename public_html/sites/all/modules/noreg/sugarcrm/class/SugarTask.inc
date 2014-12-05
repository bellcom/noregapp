<?php

class SugarTask extends SugarModel{
    private $module_name = 'Tasks';
    private $date_due_flag;
    private $date_due;
    private $date_start_flag;
    private $contact_id;
    private $priority;
    private $old_author_c;
    private $opgavetype_c;
    private $status;
    private $date_start;
    private $parent_type;
    private $parent_id;
    private $contact_name;
    private $google_response_c;
    private $old_id_c;
    private $old_published_c;
    private $old_updated_c;
    private $old_link_alt_c;
    private $old_link_self_c;
    private $old_link_edit_c;
    private $old_email_c;
    private $g_published_c;
    private $g_updated_c;
    private $name;

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