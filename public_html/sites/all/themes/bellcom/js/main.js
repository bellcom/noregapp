// Document ready
jQuery(function($){




    // --------------------------------------------------
    // Pace
    // --------------------------------------------------


    // Pace is done loading
    Pace.on( "hide", function() {


        // Enable number counter
        // enableNumberCounter.init();


    });




    // --------------------------------------------------
    // Skrollr
    // --------------------------------------------------


    // Only enable skrollr on non-touch devices
    if ( ! Modernizr.touch ) {


        // Create skrollr object
        skrollr.init({

            mobileDeceleration:                         1,
            edgeStrategy:                               "set",
            forceHeight:                                false,
            smoothScrolling:                            true,
            smoothScrollingDuration:                    200,
            easing: {
                WTF:                                    Math.random,
                inverted:                               function( p ) {
                                                            return 1-p;
                                                        }
            }

        });


    }




    // --------------------------------------------------
    // Attach footer
    // --------------------------------------------------


    // Attach footer function
    function attach_footer() {

        // Get height of footer
        var footer_height                           =   $( ".footer" ).outerHeight( true ); // Height with border and padding

        // Append the footer to the #wrapper
        $( "#wrapper" ).css( "margin-bottom", footer_height );

    }


    // Only attach footer if not touch
    if ( ! Modernizr.touch ) {

        // Attach footer
        attach_footer();

        // Window is resized
        $( window ).resize( function() {
            attach_footer();
        });

    }




    // --------------------------------------------------
    // Enable Bootstrap tooltips
    // --------------------------------------------------


    // Only enable on non-touch devices
    if ( ! Modernizr.touch ) {
        $( "[data-toggle=tooltip]" ).tooltip();
    }




    // --------------------------------------------------
    // Disable form autocomplete
    // --------------------------------------------------


    // Disable only on non-touch devices - autocomplete,
    // can be a big help on touch devices.
    if( ! Modernizr.touch ) {
        $( "form" ).attr( "autocomplete", "off" );
    }




    // --------------------------------------------------
    // Sticky header
    // --------------------------------------------------


    // Sticky navigation function
    function sticky_header() {

        // Get variables
        var body                                    =   $( "body" ),
            body_spacing                            =   ( parseInt( body.css( "margin-top" ) ) + parseInt( body.css( "padding-top" ) ) ),
            wrapper                                 =   $( "#wrapper" ),

            header                                  =   $( ".header" ),
            header_height                           =   header.outerHeight( true ),
            header_sticky_class                     =   "header-sticky",

            navigation_bar                          =   header.find( ".navigation-bar" ),
            navigation_bar_height                   =   navigation_bar.outerHeight( true ),

            header_top                              =   header.find( ".header-top" ),
            header_top_height                       =   header_top.outerHeight( true );

        // Header top doesnt exist - discontinue
        if( ! header_top.length ) return false;

        // Should be attached
        if( $( window ).scrollTop() > ( header_top_height + body_spacing ) && $( window ).width() > 991 ) {

            // It's already attached - do nothing
            if( header.hasClass( header_sticky_class ) ) return false;

            // It's not attached - attach it
            header.addClass( header_sticky_class ).css( "top", -header_top_height );

            // Prevent body from jumping
            if( body_spacing > 0 ) wrapper.css( "padding-top", header_height );
            else wrapper.css( "padding-top", header_height );

        }

        // Should not be attached
        else {

            // It's not attached (which is good) - do nothing
            if( ! header.hasClass( header_sticky_class ) ) return false;

            // It's sticky - remove stickyness
            header.removeClass( header_sticky_class ).css( "top", 0 );

            // Revoke wrapper jumping
            wrapper.css( "padding-top", 0 );

        }
    }

    // Disable only on non-touch devices - autocomplete,
    // can be a big help on touch devices.
    if( ! Modernizr.touch ) {

        // Activate while body is scrolling
        $( document ).scroll( function() {
            sticky_header();
        });

        // Activate on load
        sticky_header();

    }

    // Time tracker
    timeTracker.init();

});