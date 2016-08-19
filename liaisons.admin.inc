<?php
/**
 * Form builder to configure Liaisons options.
 *
 */
function liaisons_admin_form() {

    $form['liaisons_base_path'] = array(
        '#type' => 'textfield',
        '#title' => 'Path',
        '#description' => 'Base path for liaisons pages',
        '#default_value' => variable_get('liaisons_base_path', 'liaisons'),
        '#size' => 40
    );
    // Use custom submit function in order to rebuild menus on the way
    $form['#submit'][] = 'liaisons_admin_form_submit';

    return system_settings_form($form);
}

function liaisons_admin_form_submit($form, &$form_state) {
    // Since we're changing the path of all the liaisons menu items, we have to rebuild the menus
    // as soon as the form is submitted.
	variable_set('menu_rebuild_needed', TRUE);
}