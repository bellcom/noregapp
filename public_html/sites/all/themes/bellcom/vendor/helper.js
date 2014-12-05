

// | -- Insert button loader
// | -- Remove button loader


    // Insert button loader
    var insertButtonLoader = function( recievedConfig ) {


        // Default configurations
        var config = {
            loader:                                 jQuery( "<span />" ),
            scope:                                  "",
            icon: {
                svg:                                "svg-loader",
                noSVG:                              "fa fa-circle-o-notch fa-spin"
            },
            disableButton:                          true
        };


        // Override configurations
        jQuery.extend( config, recievedConfig );


        // No scope is set
        if( ! config.scope ) return false;


        // Disable button (link (class))
        if( config.scope.is( "a" ) && config.disableButton ) config.scope.addClass( "disabled" );


        // Disable button (button (HTML attribute))
        if( ! config.scope.is( "a" ) && config.disableButton ) config.scope.attr( "disabled", true );


        // Prepare button for the loader, keeping the dimensions
        config.scope
            .wrapInner( "<div class='normal-value' />" )
            .find( ".normal-value" )
            .css( "visibility", "hidden" )
            .css( "height", "0px" );


        // Not SVG
        if( ! Modernizr.svg || Modernizr.touch ) config.loader.addClass( config.icon.noSVG );


        // SVG
        else config.loader.addClass( config.icon.noSVG );


        // Add loader identifier class
        config.loader.addClass( "button-loader-icon" );


        // Insert loader into the button
        config.scope.append( config.loader );


        // Everything was fine...
        return true;


    };


    // Remove button loader
    var removeButtonLoader = function( recievedConfig ) {


        // Default configurations
        var config = {
            loader:                                 jQuery( "<span />" ),
            scope:                                  ""
        };


        // Override configurations
        jQuery.extend( config, recievedConfig );


        // No scope is set
        if( ! config.scope ) return false;


        // Un-disable button (via class)
        if( config.scope.hasClass( "disabled" ) ) config.scope.removeClass( "disabled" );


        // Un-disable button (via HTML attribute)
        if( config.scope.attr( "disabled", true ) ) config.scope.attr( "disabled", false );


        // Grab button value
        var buttonValue                         =   config.scope.find( ".normal-value" ).html();


        // Insert the normal button value (and thereby remove loader to)
        config.scope.html( buttonValue );


        // Everything was fine...
        return true;


    };