<?php

class SugarMeeting extends SugarModel{
    private $module_name = 'Meetings';
    private $date_modified;
    private $location;
    private $password;
    private $join_url;
    private $host_url;
    private $displayed_url;
    private $creator;
    private $external_id;
    private $duration_hours;
    private $duration_minutes;
    private $date_end;
    private $type;
    private $reminder_time;
    private $outlook_id;
    private $meeting_id_c;
    private $rec_id_c;
    private $repeat_type_c;
    private $repeat_interval_c;
    private $repeat_days_c;
    private $repeat_end_date_c;
    private $old_author_c;
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